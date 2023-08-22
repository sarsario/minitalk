/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:49:50 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 13:12:03 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	try_putchar(int c, int *total_printed)
{
	int	printed;

	printed = write(1, &c, 1);
	if (printed < 0)
		return (-1);
	*total_printed += printed;
	return (printed);
}

int	try_putstr(char *s, int *total_printed)
{
	int	printed;

	if (!s)
	{
		printed = write(1, "(null)", 6);
		if (printed < 0)
			return (-1);
	}
	else
	{
		printed = write(1, s, ft_strlen(s));
		if (printed < 0)
			return (-1);
	}
	*total_printed += printed;
	return (printed);
}
