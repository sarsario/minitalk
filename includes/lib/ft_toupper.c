/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:47:58 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 11:56:28 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts the given lowercase letter to its corresponding uppercase letter.
**
** c:	The character to convert.
**
** Returns:
** The uppercase equivalent of the given lowercase letter if the given character
** is a lowercase letter; otherwise, returns the given character unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
