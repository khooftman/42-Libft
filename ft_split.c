/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:12:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/27 18:01:03 by khooftma         ###   ########.fr       */
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

static char	**free_all(char **lst, int i)
{
	while (i >= 0)
	{
		free(lst[i]);
		i--;
	}
	free(lst);
	return (NULL);
}

/*
** Hier kan je comment zetten die dan als mouseover komt als je op de functie hovert
*/
char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	lst = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			lst[i] = ft_substr(s, 0, len);
			if (!lst[i])
				return (free_all(lst, i - 1));
			i++;
			s += len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
