/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:01:22 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/26 16:13:19 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

char	*global_msg = NULL;

int	ft_isnatural(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

int	send_bit(int pid, char c, int shift)
{
	ft_printf("Sending bit %d of [%c]\n", shift, c);
	if (c & 1 << shift)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (0);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			return (0);
	}
	return (1);
}

int	send_str(int pid, char *message)
{
	static int	i = 0;
	static int	shift = 0;

	if (!message[i])
	{
		if (shift == 8)
			return (1);
		if (!send_bit(pid, '\0', shift))
			return (0);
		shift++;
	}
	else
	{
		if (!send_bit(pid, message[i], shift))
			return (0);
		shift++;
		if (shift == 8)
		{
			i++;
			shift = 0;
		}
	}
	return (1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
	{
		if (!send_str(info->si_pid, global_msg))
		{
			ft_putstr_fd("Error: signal not sent.\n", 2);
			exit(1);
		}
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Message sent successfully.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sigset_t			block_mask;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server-pid] [message]\n");
		exit(1);
	}
	if (!ft_isnatural(argv[1]))
	{
		ft_printf("Error: Invalid PID.\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&block_mask);
	sa.sa_mask = block_mask;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not handle SIGUSR1.\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not handle SIGUSR2.\n");
		exit(1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error: Invalid PID.\n");
		exit(1);
	}
	global_msg = argv[2];
	if (!send_str(pid, global_msg))
	{
		ft_printf("Error: signal not sent.\n");
		exit(1);
	}
	while (1)
		sigsuspend(&block_mask);
	return (0);
}
