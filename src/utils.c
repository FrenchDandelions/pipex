/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:09:18 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 15:09:33 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_gnl_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s2[i] == '\0')
		return (0);
	return (1);
}

int	open_file(char *str, int i, int *fds, t_pipe *p)
{
	int	fd;

	if (i == 0)
		fd = open(str, O_RDONLY);
	if (i == 1)
		fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (i == 2)
		fd = p->heredoc_fd[0];
	if (i == 3)
		fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (fd == -1)
	{
		perror(str);
		close(fds[0]);
		close(fds[1]);
		exit(1);
	}
	return (fd);
}
