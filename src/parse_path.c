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
		j++;
	path = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) - j + 1));
	while (env[i][j++] != '\0')
	{
		path[k] = env[i][j];
		k++;
	}
	path[k] = '\0';
	return (path);
}

static char	*check_access(char *path, char *cmd, int *flag)
{
	char	*s1;
	char	*s2;

	s1 = ft_strjoin(path, "/");
	if (!s1)
		return (*flag = 1, NULL);
	s2 = ft_strjoin(s1, cmd);
	if (!s2)
		return (free(s1), *flag = 1, NULL);
	free(s1);
	if (access(s2, F_OK | X_OK) == 0)
		return (s2);
	else
		return (free(s2), NULL);
}

static void	check_all_path(char **all, int *flag)
{
	if (all == NULL)
		*flag = 1;
	return ;
}

static char	*last_check(char **all_path, char *cmd, int *flag)
{
	if (!all_path || *flag == 1)
		return (NULL);
	return (cmd);
}

char	*get_path(char *cmd, char **env, int *flag)
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
	check_all_path(all_path, flag);
	i = 0;
	while (all_path[i] != NULL && *flag == 0)
	{
		str = check_access(all_path[i], cmd, flag);
		if (str != NULL)
			return (free(path), free_array(all_path), str);
		i++;
	}
	if (ft_strcmp2(path, "0") == 1)
		free(path);
	if (all_path)
		free_array(all_path);
	return (last_check(all_path, cmd, flag));
}
