/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:46:07 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/25 16:08:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts the given uppercase letter to its corresponding lowercase letter.
**
** c:	The character to convert.
**
** Returns:
** The lowercase equivalent of the given uppercase letter if the given character
** is an uppercase letter; otherwise, returns the given character unchanged.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
