/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/04 11:51:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char** argv, char** envp)
{
	t_param	parameters;
	int		fd[2];
	int		pipe_end[2];
	int		pid;

	check_args_validity(argc, argv);
	init_params(&parameters, argv[2], argv[3]);
	find_paths(&parameters, envp);
	open_files(argv[1], argv[4], fd);
	if (pipe(pipe_end) == -1)
	{
		perror("Error\nOpenning a pipe has failed");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error\nForking has failed");
		return (0);
	}
	if (pid !=  0)
	{
		wait(NULL);
		dup2(fd[OUTFILE], STDOUT_FILENO);
		dup2(pipe_end[0], STDIN_FILENO);
		close(pipe_end[1]);
		close(fd[INFILE]);
		if (execve(parameters.correct_path2, parameters.cmd2_flags, envp) == -1)
			perror("Error\nExecve issue in the parent");
	}
	if (pid == 0)
	{
		dup2(fd[INFILE], STDIN_FILENO);
		dup2(pipe_end[1], STDOUT_FILENO);
		close(pipe_end[0]);
		close(fd[INFILE]);
		if (execve(parameters.correct_path1, parameters.cmd1_flags, envp) == -1)
			perror("Error\nExecve issue in the child");
	}
	return (0);
}

void	init_params(t_param *parameters, char *cmd1_flags, char *cmd2_flags)
{
	parameters->cmd1_flags = extract_cmd_flags(cmd1_flags);
	parameters->cmd2_flags = extract_cmd_flags(cmd2_flags);
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

char	**extract_cmd_flags(char *cmd_flags_input)
{
	char	**cmd_flags_output;
	int		line_count;
	int		i;

	i = 0;
	cmd_flags_output = ft_split(cmd_flags_input, ' ');
	line_count = count_strings(cmd_flags_output);
	while (i < line_count)
	{
		if (cmd_flags_output[i] == NULL || *cmd_flags_output[i] == ' ')
		{
			perror("Error\nCheck the cmd and flags");
			exit (1);
		}
		i++;
	}

	return (cmd_flags_output);
}

void	find_paths(t_param *parameters, char **envp)
{
	char	**path_to_builtins;

	path_to_builtins = NULL;
	path_to_builtins = find_path(envp);
	if (path_to_builtins == NULL)
		perror("Error\nCould not find the PATH=");
	path_to_builtins = add_path_sign(path_to_builtins);
	parameters->correct_path1 = check_paths(path_to_builtins, parameters->cmd1_flags[0]);
	if (parameters->correct_path1 == NULL)
		perror("Error\nPlease check cmd1");
	parameters->correct_path2 = check_paths(path_to_builtins, parameters->cmd2_flags[0]);
	if (parameters->correct_path2 == NULL)
		perror("Error\nPlease check cmd2");
}
