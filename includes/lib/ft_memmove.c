/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:46:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/14 11:09:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies len bytes from memory area src to memory area dst. The memory areas may
** overlap: copying takes place as though the bytes in src are first copied into
** a temporary array that does not overlap src or dst, and the bytes are then
** copied from the temporary array to dst.
**
** dst: A pointer to the destination array where the content is to be copied.
** src: A pointer to the source of data to be copied.
** len: The number of bytes to be copied.
**
** Returns:
** A pointer to the destination array, dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	const char	*src_char;

	if (!dst && !src)
		return (NULL);
	dst_char = dst;
	src_char = src;
	if (src_char < dst_char)
	{
		while (len--)
			*(dst_char + len) = *(src_char + len);
		return (dst);
	}
	while (len--)
		*dst_char++ = *src_char++;
	return (dst);
}
