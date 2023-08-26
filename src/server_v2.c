/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:50:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/26 16:14:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;
	static int	pid = 0;
	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error: Could not respond back to client.\n");
			exit(-1);
		}
		return ;
	}
	if (c != '\0')
	{
		ft_printf("%c", c);

		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error: Could not respond back to client.\n");
			exit(-1);
		}
	}
	else
	{
		ft_printf("\n");
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error: Could not respond back to client.\n");
			exit(-1);
		}
	}
	i = 0;
	c = 0;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&block_mask);
	sa.sa_mask = block_mask;
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
	while (1)
		pause();
	return (0);
}
