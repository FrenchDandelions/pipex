/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:50:04 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:50:05 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *str, int i)
{
	int	fd;

	if (i == 0)
		fd = open(str, O_RDONLY);
	if (i == 1)
		fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (fd == -1)
	{
		ft_dprintf(2, "fd\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static char	*find_path(char **env, char *s)
{
	int		i;
	char	*path;
	int		k;
	int		j;

	k = 0;
	i = 0;
	while (ft_strcmp2(env[i], s) != 0 && env[i])
		i++;
	j = 0;
	if (env[i] == NULL)
		return ("0");
	while (env[i][j] != '=')
	{
		j++;
	}
	path = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) - j + 1));
	while (env[i][j++] != '\0')
	{
		path[k] = env[i][j];
		k++;
	}
	path[k] = '\0';
	return (path);
}

static char	*check_access(char *path, char *cmd)
{
	char	*s1;
	char	*s2;

	s1 = ft_strjoin(path, "/");
	s2 = ft_strjoin(s1, cmd);
	free(s1);
	if (access(s2, F_OK | X_OK) == 0)
		return (s2);
	else
		return (free(s2), NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	**all_path;
	int		i;
	char	*str;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	path = find_path(env, "PATH=");
	if (!path)
		return (NULL);
	all_path = ft_split(path, ':');
	i = 0;
	while (all_path[i] != NULL)
	{
		str = check_access(all_path[i], cmd);
		if (str != NULL)
			return (free(path), free_array(all_path), str);
		i++;
	}
	free(path);
	free_array(all_path);
	return (cmd);
}
