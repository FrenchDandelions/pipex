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

void	open_in(t_pipe *p, int *fds)
{
	if (!p->is_heredoc)
	{
		p->fd_in = open_file(p->file_name, 0, fds, p);
		dup2(p->fd_in, 0);
		close(p->fd_in);
	}
	else
	{
		p->fd_in = open_file(p->file_name, 2, fds, p);
		dup2(p->fd_in, 0);
		close(p->fd_in);
	}
}

void	fork_child1(char *cmd, char **env, int *fds, t_pipe *pip)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		if (pip->i == 0 || (pip->is_heredoc && pip->i == 1))
			open_in(pip, fds);
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

void	open_out(t_pipe *p, int *fds, int *fd_out)
{
	if (!p->is_heredoc)
	{
		(*fd_out) = open_file(p->file2, 1, fds, p);
		dup2((*fd_out), 1);
		close((*fd_out));
	}
	else
	{
		(*fd_out) = open_file(p->file2, 3, fds, p);
		dup2((*fd_out), 1);
		close((*fd_out));
	}
}

void	fork_child2(char *cmd, char **env, int *fds, t_pipe *p)
{
	pid_t	pid;
	int		fd_out;

	pid = fork();
	if (pid == -1)
		exit_error("fork\n");
	else if (pid == 0)
	{
		open_out(p, fds, &fd_out);
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
