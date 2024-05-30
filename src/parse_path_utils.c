#include "pipex.h"

char	*not_found(char *cmd, char **all_path, char *path, int *flag)
{
	if (path)
		free(path);
	if (all_path)
		free_array(all_path);
	(*flag) = 2;
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found", STDERR_FILENO);
	return (ft_strdup(cmd));
}

char	*return_cmd(char *path, char **all_path, char *str)
{
	if (path)
		free(path);
	if (all_path)
		free_array(all_path);
	return (str);
}