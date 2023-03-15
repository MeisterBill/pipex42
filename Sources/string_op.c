/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:56 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/15 16:19:58 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
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

