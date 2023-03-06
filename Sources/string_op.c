/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:56 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/06 17:16:25 by artvan-d         ###   ########.fr       */
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

int	ft_putstr(char *str, char *t)
{
	if (!str)
		return (2);
	if (t)
	{
		write(2, "file: ", 7);
		write(2, t, ft_strlen(t));
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
