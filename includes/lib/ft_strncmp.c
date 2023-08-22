/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:29:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/13 18:23:54 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first n characters of two null-terminated strings s1 and s2.
**
** s1:	A pointer to the first null-terminated string.
** s2:	A pointer to the second null-terminated string.
** n:	The maximum number of characters to compare.
**
** Returns:
** An integer greater than, equal to, or less than zero
** if s1 is greater than, equal to, or less than s2, respectively.
** The comparison is done lexicographically.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
