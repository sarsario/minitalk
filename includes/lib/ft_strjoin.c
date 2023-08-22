/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:58:05 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 19:06:54 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Concatenates two strings s1 and s2 into a newly allocated string.
**
** s1:	The prefix string.
** s2:	The suffix string.
**
** Returns:
** The concatenated string, or NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*fusion;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fusion = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!fusion)
		return (NULL);
	while (*s1)
		*fusion++ = *s1++;
	while (*s2)
		*fusion++ = *s2++;
	*fusion = 0;
	fusion -= (s1_len + s2_len);
	return (fusion);
}
