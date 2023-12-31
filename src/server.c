/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:50:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/26 18:05:50 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
	return (0);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	shift = 0;
	static char	c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c |= 1 << shift;
	shift++;
	if (shift == 8)
	{
		if (!c)
		{
			ft_printf("\n");
			if (kill(info->si_pid, SIGUSR1) == -1)
				error("Error: Could not send confirmation.\n");
		}
		else
			ft_printf("%c", c);
		c = 0;
		shift = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error("Error: Could not set signal handler.\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error("Error: Could not set signal handler.\n");
	while (1)
		pause();
	return (0);
}
