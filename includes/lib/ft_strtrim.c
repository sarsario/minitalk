/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:59:02 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 20:15:40 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Trims leading and trailing characters specified in set from a string s1,
** and returns a newly allocated string with the trimmed result.
**
** s1:	The string to trim.
** set:	The set of characters to trim from s1.
**
** Returns:
** The trimmed string, or NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*result;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	result = ft_substr(start, 0, len);
	return (result);
}
