/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:17:34 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:17:36 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_pid(int *fds)
{
	int	status;

	(void)fds;
	while (errno != ECHILD)
		wait(&status);
	return (status);
}

int	new_pipes(int argc, char **argv, char **env, t_pipe *p)
{
	int	fds[2];

	p->is_heredoc = 1;
	p->i++;
	while (p->i + 2 < argc - 2)
	{
		if (pipe(fds) == -1)
			exit_error("pipe\n");
		fork_child1(argv[p->i + 2], env, fds, p);
		p->i++;
	}
	if (pipe(fds) == -1)
		exit_error("pipe\n");
	fork_child2(argv[argc - 2], env, fds, p);
	return (wait_pid(fds));
}

int	init_pipex(t_pipe *p, int argc, char **argv, char **env)
{
	p->file2 = argv[argc - 1];
	if (ft_strcmp(argv[0], "pipex") == 0 && argc > 5)
	{
		ft_dprintf(2, "Error, args should be: file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	if (ft_strcmp("here_doc", argv[1]) == 0)
	{
		if (pipe(p->heredoc_fd) == -1)
			exit_error("pipe");
		ft_heredoc(argv[2], p->heredoc_fd[1]);
		close(p->heredoc_fd[1]);
		return (new_pipes(argc, argv, env, p));
	}
	p->is_heredoc = 0;
	return (-1);
}

int	is_bonus_or_not(char *s, int argc)
{
	if ((ft_strnstr(s, "_bonus", ft_strlen(s)) == 0 && argc > 5) || argc < 5)
		return (ft_dprintf(2, "Error, args should be: file1 cmd1 cmd2 file2\n"),
			1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	t_pipe	pip;

	pip.i = 0;
	if (is_bonus_or_not(argv[0], argc))
		return (1);
	if (!env[0])
		return (0);
	if (init_pipex(&pip, argc, argv, env) == -1)
	{
		pip.file_name = argv[1];
		while (pip.i + 2 < argc - 2)
		{
			if (pipe(fds) == -1)
				exit_error("pipe\n");
			fork_child1(argv[pip.i + 2], env, fds, &pip);
			pip.i++;
		}
		if (pipe(fds) == -1)
			exit_error("pipe\n");
		fork_child2(argv[argc - 2], env, fds, &pip);
		return (wait_pid(fds));
	}
	return (0);
}
