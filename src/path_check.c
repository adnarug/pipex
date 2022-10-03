/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:18:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/03 12:57:55 by pguranda         ###   ########.fr       */
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

	builtin_paths_final = malloc(sizeof(char *) * line_count );
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
		// printf("%s \n", string_to_check);
		if (access(string_to_check, F_OK) == 0)
			return(string_to_check);
		else
			i++;
	}
	printf("Correct path not found");
	return (NULL);
}