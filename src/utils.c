/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/05 12:37:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	count_strings(char **array)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (array[i] != NULL)
	{
		i++;
		counter++;
	}
	return (counter);
}

void	check_args_validity(int argc, char **argv)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (argc != 5)
		error("Error\nInvalid arguments input - wrong number of args");
	while (i <= argc - 1)
	{
		if (argv[i] == NULL || *argv[i] == ' ')
			error("Error\nInvalid arguments input - empty parameter");
		i++;
	}
}

void	init_params(t_param *parameters, char *cmd1_flags, char *cmd2_flags)
{
	parameters->cmd1_flags = extract_cmd_flags(cmd1_flags);
	parameters->cmd2_flags = extract_cmd_flags(cmd2_flags);
}

void	error(char *message)
{
	perror(message);
	system("leaks pipex");
	exit(1);
}
