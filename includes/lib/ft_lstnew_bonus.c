/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:12:18 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/12 10:45:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates (with malloc(3)) and returns a new node. The member variable
** `content` is initialized with the value of the parameter `content`.
** The variable `next` is initialized to NULL.
**
** content:	The content to create the node with.
**
** Returns:
** The new node
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*ls;

	ls = malloc(sizeof(t_list));
	if (!ls)
		return (NULL);
	ls->content = content;
	ls->next = NULL;
	return (ls);
}
