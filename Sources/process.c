/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:54 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/20 14:21:02 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	check_if_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	ft_putstr("Error:\nCommand empty.\n", 0);
	return (1);
}

int	check_cmd(t_cmd *c)
{
	int		i;

	i = -1;
	if (access(c->cmd, X_OK) == 0)
	{
		c->cmd_access = c->cmd;
		return (1);
	}
	while (c->poss_path[++i])
	{
		c->cmd_path = ft_strjoin(c->poss_path[i], c->cmd);
		if (!c->cmd_path)
			return (0);
		if (access(c->cmd_path, X_OK) != -1)
		{
			return (1);
		}
		free(c->cmd_path);
	}
	error_cmd_msg(c->cmd);
	return (0);
}
