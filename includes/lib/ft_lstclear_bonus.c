/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:17:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/12 13:19:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Deletes and frees the given node and every successor of that node, using
** the function `del` and free(3).
** Finally, the pointer to the list must be set to NULL.
**
** lst:	The address of a pointer to a node.
** del:	The address of the function used to delete the content of the node.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_ls;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			next_ls = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_ls;
		}
		*lst = NULL;
	}
}
