/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/26 17:50:29 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	server_pid = 0;

int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
	return (0);
}

int	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (error("Error: Could not send character.\n"));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (error("Error: Could not send character.\n"));
		}
		usleep(150);
		i++;
	}
	return (1);
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (!send_char(pid, msg[i]))
			return ;
		i++;
	}
	if (!send_char(pid, '\0'))
		return ;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;

	(void)context;
	if (!pid)
		pid = server_pid;
	if (info->si_pid != pid)
		error("Error: Received message from unknown source.\n");
	if (signum == SIGUSR1)
	{
		ft_printf("Message received by server.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (error("Usage: ./client [server-pid] [message]\n"));
	if (!ft_isnumber(argv[1]))
		return (error("Error: Invalid server PID.\n"));
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1)
		return (error("Error: Invalid server PID.\n"));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (error("Error: Could not handle SIGUSR1.\n"));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (error("Error: Could not handle SIGUSR2.\n"));
	send_msg(server_pid, argv[2]);
	return (0);
}
