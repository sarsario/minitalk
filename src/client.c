/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 18:01:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	valid_pid(char *str)
{
	int	i;
	int	pid;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	if (kill(pid, 0) == -1)
		return (0);
	return (pid);
}

void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server-pid] [message]\n");
		exit(-1);
	}
	pid = valid_pid(argv[1]);
	if (!pid)
	{
		ft_printf("Invalid PID\n");
		exit(-1);
	}
	send_message(pid, argv[2]);
	return (0);
}
