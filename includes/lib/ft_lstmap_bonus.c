/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:18:15 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/17 09:38:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Iterates the list `lst` and applies the function `f` on the content
** of each node. Creates a new list resulting of the successive applications
** of the function `f`. The `del` function is used to delete the content of
** a node if needed.
**
** lst:	The address of a pointer to a node.
** f:	The address of the function used to iterate on the list.
** del:	The address of the function used to delete the content of a node.
**
** Returns:
** The new list.
** NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*f_res;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		f_res = f(lst->content);
		new_node = ft_lstnew(f_res);
		if (!new_node)
		{
			del(f_res);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
