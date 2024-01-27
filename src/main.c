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

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	i = 2;
	if (argc < 5)
		return (ft_dprintf(2, "Error, args should be: file1 cmd1 cmd2 file2\n"),
			1);
	if (!env[0])
		return (0);
	fd_in = open_file(argv[1], 0);
	dup2(fd_in, 0);
	close(fd_in);
	fd_out = open_file(argv[argc - 1], 1);
	dup2(fd_out, 1);
	close(fd_out);
	fork_child(argv[i], env);
	exec(argv[argc - 2], env);
	return (0);
}
