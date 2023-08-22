/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:00:46 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/12 09:19:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Returns a substring from the given string 's' starting at the index 'start'
** and having 'len' characters.
**
** s:		The string to extract the substring from.
** start:	The starting index of the substring.
** len:		The maximum length of the substring.
**
** Returns:
** The extracted substring, or NULL if the allocation fails or if the substring
** exceeds the bounds of the string 's'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (!*s || start >= ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (*s && start--)
		s++;
	i = 0;
	while (*s && i++ < len)
		*sub++ = *s++;
	*sub = 0;
	sub -= len;
	return (sub);
}
