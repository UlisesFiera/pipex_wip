/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:36:03 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/11 18:36:03 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

int	main


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
	
*/