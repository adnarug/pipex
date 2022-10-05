/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:18:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/05 12:34:43 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**add_path_sign(char **path_to_builtins)
{
	char	**builtin_paths_final;
	int		line_count;
	int		i;

	i = 0;
	line_count = count_strings(path_to_builtins);
	builtin_paths_final = malloc(sizeof(char *) * line_count);
	if (builtin_paths_final == NULL)
		return (NULL);
	while (path_to_builtins[i] != NULL)
	{
		builtin_paths_final[i] = ft_strjoin(path_to_builtins[i], "/");
		i++;
	}
	builtin_paths_final[i] = NULL;
	return (builtin_paths_final);
}

char	*check_paths(char **path_to_builtins, char	*command)
{
	char	*string_to_check;
	int		i;

	i = 0;
	while (path_to_builtins[i] != NULL)
	{
		string_to_check = ft_strjoin(path_to_builtins[i], command);
		if (access(string_to_check, F_OK) == 0)
			return (string_to_check);
		else
			i++;
	}
	error("Error\nCorrect path not found");
	return (NULL);
}

char	**find_path(char **envp)
{
	char	*path;
	int		i;
	char	**path_to_builtins;

	path = NULL;
	i = 0;
	if (envp == NULL || *envp == NULL)
		return (NULL);
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = envp[i];
	path_to_builtins = ft_split(path + 5, ':');
	return (path_to_builtins);
}

void	find_correct_paths(t_param *parameters, char **envp)
{
	char	**path_to_builtins;

	path_to_builtins = NULL;
	path_to_builtins = find_path(envp);
	if (path_to_builtins == NULL)
		error("Error\nCould not find the PATH =");
	path_to_builtins = add_path_sign(path_to_builtins);
	parameters->correct_path1 = \
		check_paths(path_to_builtins, parameters->cmd1_flags[0]);
	if (parameters->correct_path1 == NULL)
		error("Error\nPlease check cmd1");
	parameters->correct_path2 = \
		check_paths(path_to_builtins, parameters->cmd2_flags[0]);
	if (parameters->correct_path2 == NULL)
		error("Error\nPlease check cmd2");
}
