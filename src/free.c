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
	exit(0);
}

void	exit_error_array(char *str, char **array)
{
	ft_dprintf(2, "%s", str);
	free_array(array);
	exit(0);
}
