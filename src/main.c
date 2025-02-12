/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:36:03 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/12 17:54:05 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	execve_prep(char **cmd, char **env)
{
	
}

void	child(int *buffer, char **cmd, char **env)
{
	int	fd;

	fd = open(cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, 0);
	dup2(buffer[1], 1);
	close(buffer[0]);
	execve_prep(cmd[2], env);
}

main	(int argc, char **argv, char **env)
{
	int		buffer[2];
	pid_t	process;

	pipe(buffer);
	process = fork();
	if (process < 0)
		return (perror("Error\n"));
	if (!process)
		child(buffer, argv, env);
	else
		parent

}


/*

pipe() expects fd[0] or fd[1], one for reading and one for writing. You call
	each of them to read from one arg and write on the other

fork() creates a point from which the program starts executing itself again
	at the same time in two different processes. One process has a random
	ID, the "parent", and the other has a 0 ID, the "child". Using that, we
	can execute different things on each process.

dup() copies what a fd points to to another fd. 

dup2() interchanges two fd, and it can be used to for, say "now, the stdin is this
	file"

execve() takes what the current program is doing with another; you pass it the
	args like a command line
	
The open() commands write, create if doesn't exist or truncate to 0 if does (erases what's in it). 
	0777 is for giving permissions as in chmod

1. We take the first argument and initialize it as a file to write to.
2. We set the stdin and stdout to point to the argv[1] (the first arg) and buffer[1] (the write pipe).
	We do this because our parent will read the stdout of the write pipe fd. 


*/