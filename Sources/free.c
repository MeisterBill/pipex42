/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:46 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 16:53:29 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	free_arr(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	if (path)
		free(path);
	return (0);
}

void	free_struct(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->cmd_path)
		free(cmd->cmd_path);
	if (cmd->poss_path)
		free_arr(cmd->poss_path);
	while (cmd->args[i])
		free(cmd->args[i++]);
}

void	free_all(t_cmd *cmd1, t_cmd *cmd2)
{
	free_struct(cmd1);
	free_struct(cmd2);
}

void	error_cmd_msg(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
}
