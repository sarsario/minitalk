/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:45:18 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/12 08:30:15 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Counts the number of digits in an integer.
**
** n:	The integer to count the digits of.
**
** Returns:
** The number of digits in the integer.
*/

static int	count_digits(int n)
{
	int		digits;
	long	l;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
		l = -(long)n;
	}
	else
		l = (long)n;
	while (l > 0)
	{
		digits++;
		l /= 10;
	}
	return (digits);
}

/*
** Converts an integer into a string representation.
**
** n:	The integer to be converted.
**
** Returns:
** The string representation of the integer, or NULL if the allocation fails.
*/

char	*ft_itoa(int n)
{
	long	l;
	int		digits;
	char	*the_int;

	digits = count_digits(n);
	the_int = malloc((digits + 1) * sizeof(char));
	if (!the_int)
		return (NULL);
	the_int[digits] = '\0';
	if (n == 0)
		the_int[0] = '0';
	l = (long)n;
	if (n < 0)
	{
		l = -l;
		the_int[0] = '-';
	}
	while (l > 0)
	{
		the_int[--digits] = l % 10 + '0';
		l /= 10;
	}
	return (the_int);
}
