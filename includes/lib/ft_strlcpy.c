/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:13:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 11:55:11 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies at most 'dstsize - 1' characters from the string 'src' to 'dst',
** always adding a terminating null byte. The string 'src' must be
** null-terminated. If 'dstsize' is 0, 'dst' is not modified and the function
** returns the length of 'src'.
**
** dst:		The destination buffer.
** src:		The source string.
** dstsize:	The size of the destination buffer.
**
** Returns:
** The length of the string 'src' (excluding the terminating null byte).
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (src_len < dstsize - 1)
		cpy_len = src_len;
	else
		cpy_len = dstsize - 1;
	ft_memmove(dst, src, cpy_len);
	dst[cpy_len] = '\0';
	return (src_len);
}
