/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:49 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 17:18:07 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	init_cmd(t_cmd *cmd, int fd)
{
	cmd->fd = fd;
	cmd->poss_path = NULL;
	cmd->cmd = NULL;
	cmd->cmd_path = NULL;
	cmd->cmd_access = NULL;
	cmd->args[0] = NULL;
	cmd->checker = 0;
}

static char	**get_path(char **envp)
{
	char	**poss_path;
	char	*env_path;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", PATH))
		{
			env_path = ft_substr(envp[i], START, ft_strlen(envp[i]));
			if (!env_path)
				return (NULL);
			poss_path = ft_splitpath(env_path, ':');
			if (!poss_path)
			{
				free (env_path);
				return (NULL);
			}
			free (env_path);
			return (poss_path);
		}
	}
	return (NULL);
}

int	get_cmd(char **envp, t_cmd *cmd, char *argv)
{
	int		i;
	char	**tmp;

	i = -1;
	cmd->poss_path = get_path(envp);
	if (!cmd->poss_path)
		return (0);
	tmp = ft_splitpath(argv, ' ');
	if (!tmp)
		return (0);
	cmd->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]) - 1);
	if (!cmd->cmd)
		return (free_arr(tmp));
	while (tmp[++i])
	{
		cmd->args[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1);
		if (!cmd->args[i])
		{
			free_arr(cmd->args);
			return (free_arr(tmp));
		}
	}
	cmd->args[i] = 0;
	free_arr(tmp);
	return (1);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	int		error_checker;
	char	*c;

	c = "wc";
	error_checker = 0;
	init_commands(&cmd1, &cmd2, fd1, fd2);
	ft_shorter(envp, &cmd1, &cmd2, argv);
	if (!check_cmd(&cmd1))
		error_checker++;
	if (!check_cmd(&cmd2))
		error_checker++;
	if (!ft_strncmp(cmd2.cmd, c, 2))
		error_checker = 0;
	check_error(error_checker, &cmd1, &cmd2);
	exec_cmd(&cmd1, &cmd2, envp);
	if (cmd1.checker == 1)
		free_struct(&cmd1);
	if (cmd2.checker == 1)
		free_struct(&cmd2);
	if (cmd1.checker == 0)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		return (ft_putstr("Error:\nInvalid number of arguments.", 0));
	if (check_if_empty(argv[2]) || check_if_empty(argv[3]))
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0)
		return (ft_putstr(strerror(errno), argv[1]));
	if (fd2 < 0)
		return (ft_putstr(strerror(errno), argv[4]));
	pipex(fd1, fd2, argv, envp);
	if (close(fd1) < 0 || close(fd2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
