/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:10:33 by ntamiano          #+#    #+#             */
/*   Updated: 2023/12/13 14:36:46 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_worlds(char *str, char separator)
{
	int	number;
	int	flag;

	number = 0;
	while (*str)
	{
		flag = 0;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (flag == 0)
			{
				number++;
				flag = 1;
			}
			++str;
		}
	}
	return (number);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			j;

	len = 0;
	j = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc(len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[j++] = str[cursor++];
	next_str[j] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_numb;
	char	**vector_strings;
	int		j;

	j = 0;
	words_numb = count_worlds(str, separator);
	vector_strings = malloc(sizeof (char *) * (words_numb + 2));

	if (vector_strings == NULL)
		return (NULL);
	while (words_numb-- >= 0)
	{
		if (j == 0)
		{
			vector_strings[j] = malloc(sizeof(char));
			if (vector_strings == NULL)
				return (NULL);
			vector_strings[j++][0] = '\0';
			continue ;
		}
		vector_strings[j++] = get_next_word(str, separator);
	}
	vector_strings[j] = NULL;
	return (vector_strings);
}
