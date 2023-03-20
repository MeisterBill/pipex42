/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:56 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/20 16:46:20 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str, char *str2)
{
	if (!str)
		return (2);
	if (str2)
	{
		write(2, "file: ", 7);
		write(2, str2, ft_strlen(str2));
		write(2, ": ", 2);
	}
	while (*str)
	{
		write(2, &(*str), 1);
		str++;
	}
	write(2, "\n", 1);
	return (2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (i < n)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (result != 0 || !s1[i] || !s2[i])
			return (result);
		i++;
	}
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (len < ft_strlen(s))
		i = len;
	else
		i = ft_strlen(s);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	while ((len - i) > 0 && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
