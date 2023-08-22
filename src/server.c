/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:50:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 18:31:07 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handler(int signum)
{
	static int	i = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			exit(0);
		}
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
