/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:55:54 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 13:10:06 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	try_putbase_u(size_t nbr, const char *base, int *total_printed)
{
	size_t	base_len;
	int		printed;

	printed = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		printed = try_putbase_u(nbr / base_len, base, total_printed);
		if (printed < 0)
			return (-1);
	}
	return (try_putchar(base[nbr % base_len], total_printed));
}

int	try_putptr(void *ptr, int *total_printed)
{
	int	printed;

	if (!ptr)
		return (try_putstr("0x0", total_printed));
	printed = try_putstr("0x", total_printed);
	if (printed < 0)
		return (-1);
	return (try_putbase_u((size_t)ptr, "0123456789abcdef", total_printed));
}

int	try_putnbr(int n, int *total_printed)
{
	long	l;
	int		printed;

	printed = 0;
	l = (long)n;
	if (l < 0)
	{
		printed = try_putchar('-', total_printed);
		if (printed < 0)
			return (-1);
		l = -l;
	}
	if (l >= 10)
	{
		printed = try_putnbr(l / 10, total_printed);
		if (printed < 0)
			return (-1);
	}
	return (try_putchar(l % 10 + '0', total_printed));
}

int	try_putnbr_u(unsigned int n, int *total_printed)
{
	const char	*base = "0123456789";

	return (try_putbase_u(n, base, total_printed));
}

int	try_puthex(char c, unsigned int n, int *total_printed)
{
	char	*base;

	base = NULL;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		return (-1);
	return (try_putbase_u((size_t)n, base, total_printed));
}
