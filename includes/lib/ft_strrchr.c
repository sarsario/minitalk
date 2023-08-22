/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:41:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/13 18:16:26 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the last occurrence of character c (converted to a char) in the
** string s.
**
** s:	A pointer to the null-terminated string to be searched.
** c:	The character to search for. It is converted to a char.
**
** Returns:
** A pointer to the last occurrence of the character c in the string s.
** If the character is not found, it returns a NULL pointer.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && (unsigned char)c != s[len])
		len--;
	if ((unsigned char)c == s[len])
		return ((char *)(s + len));
	return (NULL);
}
