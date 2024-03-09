/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:15:41 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:15:43 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	pid_t	pid;
}			t_pipe;

void		free_array(char **array);
void		exec(char *cmd, char **env);
int			open_file(char *str, int i, int *fds);
void		fork_child1(char *cmd, char **env, int *fds, char *s, int i);
char		*get_path(char *cmd, char **env, int *flag);
int			ft_strcmp2(char *s1, char *s2);
void		exit_error(char *str);
void		exit_error_array(char *str, char **array);
void		fork_child2(char *cmd, char **env, int *fds, char *s);

#endif