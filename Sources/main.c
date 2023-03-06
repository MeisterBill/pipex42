/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:49 by artvan-d          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:39 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	pipex(int fd1, int fd2, char **argv, char **env)
{
	
}

int	main(int ac, char **argv, char **env)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		return (ft_putstr("Error:\nUse <./pipex infile cmd1 cmd2 \
		outfile> to run this program.\n", 0));
	if (check_if_empty(argv[2]) || check_if_empty(argv[3]))
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0)
		return (ft_putstr(sterror(errno), argv[1]));
	if (fd2 < 0)
		return (ft_putstr(sterror(errno), argv[4]));
	pipex(fd1, fd2, argv, env);
	if (close(fd1) < 0 || close(fd2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
