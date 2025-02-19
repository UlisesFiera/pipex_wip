/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:36:03 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 09:22:01 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	execute(char *cmd, char **env)
{
	char	**split_cmd;
	char	*cmd_path;

	split_cmd = ft_split(cmd, ' ');
	cmd_path = ft_getpath(split_cmd[0], env);
	if (execve(cmd_path, split_cmd, env) == -1)
	{
		ft_printf("execve couldn't find command: %s\n", split_cmd[0]);
		ft_free_tab(split_cmd);
		exit(0);
	}
}

void	child(int *end, char **file_cmd, char **env)
{
	int	fd;

	fd = open(file_cmd[1], O_RDONLY, 0777);
	dup2(fd, 0);
	dup2(end[1], 1);
	close(end[0]);
	execute(file_cmd[2], env);
}

void	parent(int *end, char **file_cmd, char **env)
{
	int	fd;

	fd = open(file_cmd[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	wait(NULL);
	dup2(fd, 1);
	dup2(end[0], 0);
	close(end[1]);
	execute(file_cmd[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		end[2];
	pid_t	pid1;

	(void)argc;
	if (pipe(end) == -1)
		return (ft_printf("pipe failure\n"));
	pid1 = fork();
	if (pid1 < 0)
		return (ft_printf("fork failure\n"));
	if (!pid1)
		child(end, argv, env);
	else
		parent(end, argv, env);
}

/*

pipe() expects fd[0] or fd[1], one for reading and one for writing. You call
	each of them to read from one arg and write on the other

fork() creates a point from which the program starts executing itself again
	at the same time in two different processes. One process has a random
	ID, the "parent", and the other has a 0 ID, the "child". Using that, we
	can execute different things on each process.

dup() copies what a fd points to to another fd. 

dup2() interchanges two fd, and it can be used to for, say "now, 
	the stdin is this file"

execve() takes what the current program is doing with another; you pass it the
	args like a command line
	
The open() commands write, create if doesn't exist or truncate to 0 if does 
	(erases what's in it). 
		0777 is for giving permissions as in chmod

1. We get into the child process.
	1. We take the first argument and initialize it as a file to write to.
	2. We declare that the stdin of this process is that file, so we'll 
		use its content as input
	3. We declare that the sdout will be the writing end of the pipe; the child.
	4. We do all that so execve takes as argument the new stdin 
		(the file) and puts the result of the called command into 
		the new stdout (the pipe).

*/