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
		ft_dprintf(2, "%s: command not found\n", cmds[0]);
		free_array(cmds);
		exit(1);
	}
}
