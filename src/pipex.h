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

void	free_array(char **array);
void	exec(char *cmd, char **env);
int		open_file(char *str, int i);
void	fork_child(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
int		ft_strcmp2(char *s1, char *s2);
void	exit_error(char *str);
void	exit_error_array(char *str, char **array);

#endif