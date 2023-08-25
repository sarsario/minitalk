/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/25 17:21:12 by osarsari         ###   ########.fr       */
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

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (message[i] >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [message]\n", 2);
		exit(-1);
	}
	if (!ft_isnumber(argv[1]))
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(-1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(-1);
	}
	send_message(pid, argv[2]);
	return (0);
}
