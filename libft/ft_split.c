/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:58:44 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 14:53:37 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static int	count_words(char const *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_separator(str[i], sep))
		{
			words++;
			while (str[i] && !is_separator(str[i], sep))
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word_splitter(char const *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_separator(str[i], sep))
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !is_separator(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	helper(char const *s, char c, char **words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_separator(s[i], c))
		{
			words[j] = word_splitter(&s[i], c);
			if (words[j] == NULL)
				return (-1);
			while (s[i] && !is_separator(s[i], c))
				i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	j = helper(s, c, words);
	if (j == -1)
	{
		while (words[i] != NULL)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (NULL);
	}
	words[j] = NULL;
	return (words);
}
