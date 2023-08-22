/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:44:32 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/12 18:17:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
**
** dst:	A pointer to the destination array where the content is to be copied.
** src:	A pointer to the source of data to be copied.
** n:	The number of bytes to be copied.
**
** Returns:
** A pointer to the destination array, which is dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_char;
	const char	*src_char;

	if (!dst && !src)
		return (NULL);
	dst_char = dst;
	src_char = src;
	while (n--)
		*dst_char++ = *src_char++;
	return (dst);
}
