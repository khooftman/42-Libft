/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:12:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/28 18:07:12 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_free_all(char **words, int j)
{
	while (j >= 0)
		free(words[j--]);
	free(words);
	return (NULL);
}

static char	*word_split(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		words[j] = word_split(&s[i], c);
		if (!words[j])
			return (ft_free_all(words, j));
		i += ft_strlen(words[j++]);
	}
	words[j] = NULL;
	return (words);
}
