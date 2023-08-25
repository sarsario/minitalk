/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/25 19:21:36 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	ft_isnumber(char *pid)
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

// while (message[i])
// 	{
// 		j = 0;
// 		while (j < 8)
// 		{
// 			bit = (message[i] >> j) & 1;
// 			if (bit == 1)
// 				kill(pid, SIGUSR1);
// 			else
// 				kill(pid, SIGUSR2);
// 			usleep(100);
// 			j++;
// 		}
// 		i++;
// 	}

int	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		usleep(100);
		i++;
	}
	return (1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		ft_printf("Message received by server.\n");
	else if (signum == SIGUSR2)
		ft_printf("Error: Message not received by server.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server-pid] [message]\n");
		return (0);
	}
	if (!ft_isnumber(argv[1]))
	{
		ft_printf("Error: Invalid PID.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not handle SIGUSR1.\n");
		exit(-1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not handle SIGUSR2.\n");
		exit(-1);
	}
	i = 0;
	while (argv[2][i])
	{
		if (!send_char(pid, argv[2][i]))
		{
			ft_printf("Error: Could not send character.\n");
			exit(-1);
		}
		i++;
	}
	if (!send_char(pid, '\0'))
	{
		ft_printf("Error: Could not send character.\n");
		exit(-1);
	}
	return (0);
}
