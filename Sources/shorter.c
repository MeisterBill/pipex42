/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:14:11 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 17:18:15 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	init_commands(t_cmd *cmd1, t_cmd *cmd2, int fd1, int fd2)
{
	init_cmd(cmd1, fd1);
	init_cmd(cmd2, fd2);
}

int	check_error(int error_checker, t_cmd *cmd1, t_cmd *cmd2)
{
	int	i;

	if (error_checker > 0)
	{
		i = 0;
		if (cmd1->cmd)
			free(cmd1->cmd);
		if (cmd1->poss_path)
			free_arr(cmd1->poss_path);
		while (cmd1->args[i])
			free(cmd1->args[i++]);
		i = 0;
		if (cmd2->cmd)
			free(cmd2->cmd);
		if (cmd2->poss_path)
			free_arr(cmd2->poss_path);
		while (cmd2->args[i])
			free(cmd2->args[i++]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_shorter(char **envp, t_cmd *cmd1, t_cmd *cmd2, char **argv)
{
	if (!get_cmd(envp, cmd1, argv[2]) || !get_cmd(envp, cmd2, argv[3]))
	{
		free_all(cmd1, cmd2);
		exit(EXIT_FAILURE);
	}
}
