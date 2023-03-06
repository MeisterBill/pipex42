/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:43 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/06 15:55:44 by artvan-d         ###   ########.fr       */
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

typedef struct s_cmd
{
	char	*cmd;
	char	**path;
	char	*cmd_path;
	char	*cmd_access;
	char	*args[100];
	int		fd;
}	t_cmd;

#endif