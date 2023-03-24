#include "../Includes/pipex.h"

void	init_commands(t_cmd *cmd1, t_cmd *cmd2, int fd1, int fd2)
{
	init_cmd(cmd1, fd1);
	init_cmd(cmd2, fd2);
}

int	check_error(int error_checker)
{
	if (error_checker > 0)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}