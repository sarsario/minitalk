/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:05:02 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/13 18:14:09 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates sufficient memory for a copy of the string 's1', does the copy,
** and returns a pointer to it. The pointer may subsequently be used as an
** argument to the function free(3). If insufficient memory is available,
** NULL is returned.
**
** s1:	The string to be duplicated.
**
** Returns:
** The pointer to the new duplicate string or NULL if insufficient
** memory was available.
*/

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (*s1)
		*dup++ = *s1++;
	*dup = 0;
	dup -= len;
	return (dup);
}
