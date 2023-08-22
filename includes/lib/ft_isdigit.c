/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:25:21 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/18 16:20:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the given character is a digit.
** A digit is a character that represents a number from 0 to 9.
**
** c:	The character to be checked.
**
** Returns:
** Non-zero value if the character is a digit, 0 otherwise.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
