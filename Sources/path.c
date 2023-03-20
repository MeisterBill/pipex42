/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:51 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/20 14:32:31 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	return (0);
}

static int	nb_words(const char *str, char c)
{
	int	i;
	int	count;

	if (!str || !str[0])
		return (0);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if ((str[i] != c && str[i + 1] == c) || (str[i] != c \
		&& str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

static int	words_len(const char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str && str[i] && str[i] == c)
		i++;
	while (str && str[i] && str[i++] != c)
		len++;
	return (len);
}

static char	**fill_tab(int words, const char *str, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < words)
	{
		j = 0;
		tab[k] = (char *)malloc(sizeof(char) * (words_len(str, c, i) + 2));
		if (!tab)
			return (free_tab(tab));
		while (str && str[i] && str[i] == c)
			i++;
		while (str && str[i] && str[i] != c)
			tab[k][j++] = str[i++];
		tab[k][j++] = '/';
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_splitpath(char *str, char c)
{
	char	**tab;
	int		words;

	if (!str || !str[0])
		return (NULL);
	words = nb_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = fill_tab(words, str, c, tab);
	return (tab);
}
