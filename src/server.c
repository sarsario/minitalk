/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:50:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/23 14:23:28 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	copy_over(pid_t sender_id)
{
	kill(sender_id, SIGUSR2);
}

int	set_sender_id(int sender_id, siginfo_t *info)
{
	if (!sender_id)
		sender_id = info->si_pid;
	if (sender_id != info->si_pid)
	{
		ft_putstr_fd("Error: message from another client\n", 2);
		exit(1);
	}
	return (sender_id);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int		i = 0;
	static char		c = 0;
	static pid_t	sender_id = 0;

	(void)context;
	sender_id = set_sender_id(sender_id, info);
	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			copy_over(sender_id);
			sender_id = 0;
		}
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
