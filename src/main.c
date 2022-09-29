/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/29 17:58:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char** argv, char** envp)
{
	char	**path_to_builtins;
	t_param	parameters;
	// int		fd[2];
	// int		id;
	// int		input;
	// char	cmd[] = "/usr/bin/say";

	sort_params(argv, &parameters);
	path_to_builtins = find_path(envp);
	// check_paths(path_to_builtins, &parameters);
	// execve(cmd, argv, NULL);
	// printf("check");
	// //fd[0] - read
	// //fd[1] - write
	// input = 42;
	// path.pid1 = 0;
	// path.pid2 = 0;

	// pipe(fd);
	// id = fork();
	// if (id == 0)
	// {
	// 	input = 21;
	// 	close(fd[0]);
	// 	write(fd[1], &input, sizeof(int));
	// 	close(fd[1]);
	// }
	// if (id != 0)
	// {
	// 	close(fd[1]);
	// 	read(fd[0], &input, sizeof(int));
	// 	close(fd[0]);
	// 	printf("Got this from the child %d", input);
	// }
	// path.pid1 = fork();
	// if (path.pid2 == 0)
	// {
	// 		execv(envp[2], argv[1]);
	// }
	// if (path.pid1 == 0)
	// {
	// 	pipe()
	// }
	return (0);
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
	print_2d(path_to_builtins);
	return (path_to_builtins);
}

void	sort_params(char **argv, t_param *parameters)
{
	extract_cmd_flags(argv[1], parameters);
}

void	extract_cmd_flags(char *commands_flags, t_param *parameters)
{
	char	**table_of_commands_flags;
	int		i;
	char	*command;
	t_list	*first_flag;
	t_list	*flags;
	t_list	*head_flag;

	i = 0;
	table_of_commands_flags = ft_split(commands_flags, ' ');
	parameters->command = table_of_commands_flags[i];
	command = table_of_commands_flags[i];
	i++;
	first_flag = ft_lstnew(table_of_commands_flags[i]);
	head_flag = first_flag;
	i++;
	while (table_of_commands_flags[i] != NULL)
	{
		flags = ft_lstnew(table_of_commands_flags[i]);
		ft_lstadd_back(&first_flag, flags);
		first_flag = flags;
		i++;
	}
	init_params(parameters, head_flag);
}

void	init_params(t_param *parameters, t_list *cmd_flags)
{
	parameters->infile = NULL;
	parameters->outfile = NULL;
	parameters->infile_fd = 0;
	parameters->flags = cmd_flags;
	parameters->outfile_fd = 0;
}

char	*check_paths(char** path_to_check, t_param *parameters)
{
	ft_strjo
}

char	add_path_sign(char *s)
{
	
}