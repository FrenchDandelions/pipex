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

	cmds = ft_split(cmd, ' ');
	if (!cmds[0])
		exit_error_array("command not found: ' '\n", cmds);
	path = get_path(cmds[0], env);
	if (execve(path, cmds, env) == -1)
	{
		ft_dprintf(2, "command not found: %s\n", cmds[0]);
		free_array(cmds);
		exit(1);
	}
}
