/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:33:05 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:33:07 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_and_exit(char **env)
{
	int	errno_before;

	errno_before = errno;
	perror(env[0]);
	free_array(env);
	errno = errno_before;
	exit(126);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**cmds;
	int		i;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (!cmds)
		exit_error("malloc\n");
	if (!cmds[0])
	{
		ft_dprintf(2, "%s", cmd);
		exit_error_array(": command not found\n", cmds);
	}
	path = get_path(cmds[0], env, &i);
	if (path == NULL)
		exit_error_array("malloc\n", cmds);
	if (execve(path, cmds, env) == -1)
	{
		if (errno == EACCES)
			free_and_exit(cmds);
		ft_dprintf(2, "%s: command not found\n", cmds[0]);
		free_array(cmds);
		exit(1);
	}
}
