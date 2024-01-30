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

void	fork_child1(char *cmd, char **env, int *fds)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		exec(cmd, env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		return ;
	}
}

void	fork_child2(char *cmd, char **env, int *fds)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		close(fds[0]);
		close(fds[1]);
		exec(cmd, env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		return ;
	}
}
