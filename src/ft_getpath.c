/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:50:46 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 09:20:21 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

char	*find_exec(char **all_dir, char *cmd)
{
	int		i;
	char	*path;
	char	*exec;

	i = 0;
	while (all_dir[i])
	{
		path = ft_strjoin(all_dir[i], "/");
		exec = ft_strjoin(path, cmd);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(all_dir);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_tab(all_dir);
	return (NULL);
}

char	*ft_getpath(char *cmd, char **env)
{
	char	**all_dir;

	all_dir = ft_split(ft_getenv("PATH", env), ':');
	return (find_exec(all_dir, cmd));
}

/*

We need to find where the cmd passed is in the system so we can use it.

1. We get all the directories where our command might be by getting the
	full path stored in the PATH env and splitting it by directories.
2. We then try to access our cmd putting the path of each dir in front
	of it (user/bin/ls), and check if that exists as a program with access.

*/