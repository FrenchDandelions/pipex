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
	close(fds[0]);
	close(fds[1]);
	while (errno != ECHILD)
		wait(&status);
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	int	fds[2];

	if (argc != 5)
		return (ft_dprintf(2, "Error, args should be: file1 cmd1 cmd2 file2\n"),
			1);
	if (!env[0])
		return (0);
	if (pipe(fds) == -1)
		exit_error("pipe\n");
	fork_child1(argv[2], env, fds, argv[1]);
	if (pipe(fds) == -1)
		exit_error("pipe\n");
	fork_child2(argv[argc - 2], env, fds, argv[argc - 1]);
	return (wait_pid(fds));
}
