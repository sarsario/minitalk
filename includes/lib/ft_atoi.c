/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:07:09 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/18 16:18:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert the initial portion of a string pointed to by `str` to an integer.
**
** str:	The string to be converted.
**
** Returns:
** The converted integer value. Behavior undefined if the the integer > INT_MAX
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
		neg = *str++ == '-';
	while (*str && *str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	if (neg)
		res = -res;
	return ((int)res);
}
