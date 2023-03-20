/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:43 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/20 15:47:34 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# define PATH 5
# define START 6

typedef struct s_cmd
{
	char	*cmd;
	char	**poss_path;
	char	*cmd_path;
	char	*cmd_access;
	char	*args[100];
	int		fd;
}	t_cmd;

// FREE
int		free_arr(char **path);
void	free_struct(t_cmd *cmd);
void	free_all(t_cmd *cmd1, t_cmd *cmd2);
void	error_cmd_msg(char *str);

// MAIN
void	pipex(int fd1, int fd2, char **argv, char **env);

// PATH
char	**ft_splitpath(char *str, char c);

// CMD CHECK AND PROCESSES
int		check_if_empty(char *str);
int		check_cmd(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd1, t_cmd *cmd2, char **env);

// STRING OPERATIONS
int		ft_strlen(char *str);
int		ft_putstr(char *str, char *str2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, const char *s2);

#endif