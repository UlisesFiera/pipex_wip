/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:02:31 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/13 11:02:31 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

char	*ft_getenv(char *env_name, char **env)
{
	int		i;
	int		j;
	char	*env_sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		env_sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(env_sub, env_name) == 0)
		{
			free(env_sub);
			return (env[i] + j + 1);
		}
		free(env_sub);
		i++;
	}
	return (NULL);
}

/*

We iterate through all our envs until we get the one that
starts with PATH, and return all after PATH=, which will
be our path.

*/