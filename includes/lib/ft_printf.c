/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:12:31 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 13:12:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_supported_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	try_putconversion(char c, va_list *args, int *total_printed)
{
	if (c == 'c')
		return (try_putchar(va_arg(*args, int), total_printed));
	else if (c == 's')
		return (try_putstr(va_arg(*args, char *), total_printed));
	else if (c == 'p')
		return (try_putptr(va_arg(*args, void *), total_printed));
	else if (c == 'd' || c == 'i')
		return (try_putnbr(va_arg(*args, int), total_printed));
	else if (c == 'u')
		return (try_putnbr_u(va_arg(*args, unsigned int), total_printed));
	else if (c == 'x' || c == 'X')
		return (try_puthex(c, va_arg(*args, unsigned int), total_printed));
	else if (c == '%')
		return (try_putchar(c, total_printed));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total_printed;

	total_printed = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			if (!is_supported_conversion(*(s + 1)))
				return (total_printed);
			if (try_putconversion(*(++s), &args, &total_printed) < 0)
				return (total_printed);
		}
		else
		{
			if (try_putchar(*s, &total_printed) < 0)
				return (total_printed);
		}
		s++;
	}
	va_end(args);
	return (total_printed);
}
