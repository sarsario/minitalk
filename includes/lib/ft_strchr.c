/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:51:11 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/18 16:22:31 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the first occurrence of the character c (an unsigned char)
** in the string pointed to by s.
**
** s:	The string to search in.
** c:	The character to search for.
**
** Returns:
** A pointer to the first occurrence of the character c in the string s,
** or NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (NULL);
}
