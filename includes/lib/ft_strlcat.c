/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:10:25 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/08 17:11:11 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the string `src` to the end of `dst` with a size limit of `dstsize`.
** Appends a null-terminating character to the end of the result.
** If `dstsize` is 0, the result is the length of `src`.
** Returns the total length of the string it tried to create.
**
** dst:		The destination string.
** src:		The source string to append to `dst`.
** dstsize:	The maximum size of the resulting string.
**
** Returns:
** The total length of the string it tried to create.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = dst_len;
	while (*src && i < dstsize - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	if (dst_len > dstsize)
		dst_len = dstsize;
	return (dst_len + src_len);
}
