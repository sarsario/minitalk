/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:32:37 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/13 18:12:49 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches the initial n bytes of the memory area pointed to by s for
** the first occurrence of the character c (interepreted as an unsigned char).
**
** s:	A pointer to the memory area to be searched.
** c:	The character to be searched.
** n:	The number of bytes to be searched.
**
** Returns:
** A pointer to the first occurrence of the character c in the memory area s,
** or NULL if the character is not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((unsigned char)c == *(unsigned char *)s)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
