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

# define ERR "Pipex: warning: mini_doc delimited by end-of-file (wanted `"

typedef struct s_pipe
{
	char	*file_name;
	char	*file2;
	int		i;
	int		fd_in;
	int		heredoc_fd[2];
	int		is_heredoc;
}			t_pipe;

void		free_array(char **array);
void		exec(char *cmd, char **env);
int			open_file(char *str, int i, int *fds, t_pipe *p);
void		fork_child1(char *cmd, char **env, int *fds, t_pipe *pip);
char		*get_path(char *cmd, char **env, int *flag);
int			ft_strcmp2(char *s1, char *s2);
void		exit_error(char *str);
void		exit_error_array(char *str, char **array);
void		fork_child2(char *cmd, char **env, int *fds, t_pipe *pip);
char		*get_next_line(int fd);
int			ft_heredoc(char *lim, int fd);
char		*ft_gnl_strchr(char *s, int c);
size_t		ft_gnl_strlen(char *s);

#endif