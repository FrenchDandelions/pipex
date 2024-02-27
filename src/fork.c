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

void	fork_child1(char *cmd, char **env, int *fds, char *s)
{
	pid_t	pid;
	int		fd_in;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		fd_in = open_file(s, 0, fds);
		dup2(fd_in, 0);
		close(fd_in);
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

void	fork_child2(char *cmd, char **env, int *fds, char *s)
{
	pid_t	pid;
	int		fd_out;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		fd_out = open_file(s, 1, fds);
		dup2(fd_out, 1);
		close(fd_out);
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
