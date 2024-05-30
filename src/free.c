/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:59:20 by thole             #+#    #+#             */
/*   Updated: 2024/01/27 14:59:21 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	exit_error(char *str)
{
	ft_dprintf(2, "%s", str);
	exit(1);
}

void	exit_error_array(char *str, char *s1, char **cmds, int index)
{
	if (index == 1 && !s1)
		ft_putstr_fd(cmds[0], STDERR_FILENO);
	else if (index == 1 && s1 && !s1[0])
		ft_putstr_fd(s1, STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	if (s1)
		ft_memdel(s1);
	if (cmds)
		free_array(cmds);
	if (index == 1)
		exit(127);
	exit(-2);
}
