/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:27:48 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/18 16:19:42 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the given character is an ASCII character.
**
** c:	The character to be checked.
**
** Returns:
** Non-zero if the character is an ASCII character, 0 otherwise.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
