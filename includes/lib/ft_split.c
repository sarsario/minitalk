/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/18 16:22:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Counts the number of substrings in a given string.
**
** s:	The string to count the substrings of.
** c:	The delimiter character.
**
** Returns:
** The number of substrings in the string.
*/

static int	count_words(char const *s, char c)
{
	int	word_count;

	if (!s)
		return (0);
	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			word_count++;
		}
	}
	return (word_count);
}

/*
** Extracts a substring from a given string until the delimiter character.
**
** s:	The string to extract the substring from.
** c:	The delimiter character.
**
** Returns:
** The extracted substring, or NULL if the allocation fails.
*/

static char	*extract_word(char const *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	word = (char *)s;
	while (*word && *word != c)
	{
		word++;
		len++;
	}
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (*s && *s != c)
		*word++ = *s++;
	*word = 0;
	return (word - len);
}

/*
** Frees the memory allocated for an array of strings and sets it to NULL.
**
** split:	The array of strings to be freed.
** size:	The number of elements in the array.
**
** Returns:
** NULL.
*/

static char	**ft_free(char **arr, int elem)
{
	while (elem >= 0)
		free(arr[elem--]);
	free(arr);
	return (NULL);
}

/*
** Fills an array of strings with substrings of a given string.
**
** split:		The array of strings to be filled.
** s:			The string to be split.
** word_count:	The number of substrings to be extracted.
** c:			The delimiter character.
**
** Returns:
** A pointer to the array of strings containing the substrings.
*/

static char	**ft_fill_split(char **split, char const *s, int word_count, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word = extract_word(s, c);
			if (!word)
				return (ft_free(split, i - 1));
			split[i] = word;
			s += ft_strlen(word);
			i++;
		}
	}
	split[word_count] = NULL;
	return (split);
}

/*
** Splits a string into an array of substrings based on a delimiter character.
**
** s:	The string to be split.
** c:	The delimiter character.
**
** Returns:
** A pointer to an array of strings that contains the substrings,
** or NULL if the allocation fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_split(split, s, word_count, c));
}
