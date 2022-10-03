/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/03 18:44:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
- Sorting params - cmds and flags - into struct
- Extracting paths
- TODO: add / to the paths*/
int main(int argc, char** argv, char** envp)
{
	char	**path_to_builtins;
	t_param	parameters;
	char	*correct_path;
	int		fd[2];
	int		pipe_end[2];
	//pipe_end[0] - read, infile
	//pipe_end[1] - write, outfile 
	int		pid;
	char	**cmd1_flags;
	char	**cmd2_flags;

	// if (argc != 5)
	// 	return 0;);
	cmd1_flags = extract_cmd_flags(argv[2], parameters.cmd1);

	cmd2_flags = extract_cmd_flags(argv[3], parameters.cmd2);
	// ft_printf("cmd1: %s cmd2: %s path1: %s path2: %s \n", parameters.cmd1, parameters.cmd2, parameters.correct_path1, parameters.correct_path2);
	path_to_builtins = find_path(envp);
	path_to_builtins = add_path_sign(path_to_builtins);
	parameters.correct_path1 = check_paths(path_to_builtins, cmd1_flags[0]);
	parameters.correct_path2 = check_paths(path_to_builtins, cmd2_flags[0]);
	// printf("%s", parameters.correct_path2);
	open_files("/Users/pguranda/Projects/pipex/src/infile", "/Users/pguranda/Projects/pipex/src/outfile", fd);
	pipe(pipe_end);//check if success
	pid = fork();
	/*
	0 - STDIN
	1 - STDOUT
	3 - pipe[1]
	4 - pipe[2]
	*/
	// Parent is writing cmd1 to outfile
	if (pid != 0)
	{
		wait(NULL);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipe_end[0], STDIN_FILENO);
		close(pipe_end[1]);
		close(fd[1]);
		execve(parameters.correct_path2, cmd2_flags, envp);
		printf("Check the file, sir!");
	}
	// //Child writes into the infile
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipe_end[1], STDOUT_FILENO);
		close(pipe_end[0]);
		close(fd[1]);
		execve(parameters.correct_path1, cmd1_flags, envp);
	}
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
	// print_2d(path_to_builtins);
	return (path_to_builtins);
}

char	**extract_cmd_flags(char *cmd_flags_input, char *cmd)
{
	char	**cmd_flags_output;
	int		i;
	// t_list	*first_flag;
	// t_list	*flags;
	// t_list	*head_flag;

	i = 0;
	cmd_flags_output = ft_split(cmd_flags_input, ' ');
	cmd = cmd_flags_output[i];
	// command = table_of_commands_flags[i];
	// i++;
	// first_flag = ft_lstnew(table_of_commands_flags[i]);
	// head_flag = first_flag;
	// i++;
	// while (table_of_commands_flags[i] != NULL)
	// {
	// 	flags = ft_lstnew(table_of_commands_flags[i]);
	// 	ft_lstadd_back(&first_flag, flags);
	// 	first_flag = flags;
	// 	i++;
	// }
	// flags = head_flag;
	// init_params(parameters, head_flag);
	return (cmd_flags_output);
}

// void	init_params(t_param *parameters, t_list *cmd_flags)
// {
// 	parameters->infile = NULL;
// 	parameters->outfile = NULL;
// 	parameters->infile_fd = 0;
// 	parameters->flags = cmd_flags;
// 	parameters->outfile_fd = 0;
// }
