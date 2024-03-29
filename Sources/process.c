/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:54 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 17:05:31 by artvan-d         ###   ########.fr       */
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
	ft_putstr("Error:\nCommand empty.", 0);
	return (1);
}

int	check_cmd(t_cmd *cmd)
{
	int		i;

	i = -1;
	if (access(cmd->cmd, X_OK) == 0)
	{
		cmd->cmd_access = cmd->cmd;
		cmd->checker = 1;
		return (1);
	}
	while (cmd->poss_path[++i])
	{
		cmd->cmd_path = ft_strjoin(cmd->poss_path[i], cmd->cmd);
		if (!cmd->cmd_path)
			return (0);
		if (access(cmd->cmd_path, X_OK) != -1)
		{
			cmd->checker = 1;
			return (1);
		}
		free(cmd->cmd_path);
	}
	error_cmd_msg(cmd->cmd);
	return (0);
}

static void	child_one(int *pipefd, t_cmd *cmd, char **env)
{
	if (dup2(cmd->fd, STDIN_FILENO) < 0 || dup2(pipefd[1], STDOUT_FILENO) < 0)
		return (perror("Child One"));
	close(pipefd[0]);
	if (cmd->checker == 1)
	{
		if (cmd->cmd_access)
		{
			if (execve(cmd->cmd_access, cmd->args, env) == -1)
				ft_putstr(strerror(errno), 0);
		}
		else
		{
			if (execve(cmd->cmd_path, cmd->args, env) == -1)
				ft_putstr(strerror(errno), 0);
		}
	}
	else
		exit(EXIT_FAILURE);
}

static void	child_two(int *pipefd, t_cmd *cmd2, t_cmd *cmd1, char **env)
{
	if (dup2(cmd2->fd, STDOUT_FILENO) < 0 || dup2(pipefd[0], STDIN_FILENO) < 0)
	{
		if (cmd1->checker == 0)
			exit(EXIT_FAILURE);
		return (perror("Child Two"));
	}
	close(pipefd[1]);
	if (cmd2->checker == 1)
	{
		if (cmd2->cmd_access)
		{
			if (execve(cmd2->cmd_access, cmd2->args, env) == -1)
				ft_putstr(strerror(errno), 0);
		}
		else
		{
			if (execve(cmd2->cmd_path, cmd2->args, env) == -1)
				ft_putstr(strerror(errno), 0);
		}
	}
	else
		exit(EXIT_FAILURE);
}

void	exec_cmd(t_cmd *cmd1, t_cmd *cmd2, char **env)
{
	int		status;
	int		pipefd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	status = 0;
	pipe(pipefd);
	pid_1 = fork();
	if (pid_1 < 0)
		return (perror("Fork One"));
	if (!pid_1)
		child_one(pipefd, cmd1, env);
	pid_2 = fork();
	if (pid_2 < 0)
		return (perror("Fork Two"));
	if (!pid_2)
		child_two(pipefd, cmd2, cmd1, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}
