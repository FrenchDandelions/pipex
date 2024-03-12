/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:48:13 by thole             #+#    #+#             */
/*   Updated: 2024/03/10 18:48:15 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc(char *lim, int fd)
{
	char	*str;

	while (1)
	{
		ft_printf("> ");
		str = get_next_line(0);
		if (!str)
		{
			ft_dprintf(2, "\033[1;31m%s%s'')\n\033[0m", ERR, lim);
			break ;
		}
		if (ft_strncmp(str, lim, (int)ft_strlen(lim)) == 0)
			break ;
		ft_dprintf(fd, "%s", str);
		free(str);
	}
	if (str)
		free(str);
	return (1);
}
