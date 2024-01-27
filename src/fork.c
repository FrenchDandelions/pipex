/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:42:48 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:42:49 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_child(char *cmd, char **env)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		exit_error("pipe\n");
	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		exec(cmd, env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		return ;
	}
}
