/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/05 12:42:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	parameters;
	int		fd[2];
	int		pipe_end[2];
	int		pid;

	check_args_validity(argc, argv);
	init_params(&parameters, argv[2], argv[3]);
	find_correct_paths(&parameters, envp);
	printf("Hi");
	open_files(argv[1], argv[4], fd);
	if (pipe(pipe_end) == -1)
		error("Error\nCould not open the pipe");
	pid = fork();
	if (pid == -1)
		error("Error\nCould not fork");
	if (pid != 0)
		parent_process(parameters, fd, pipe_end, envp);
	if (pid == 0)
		child_process(parameters, fd, pipe_end, envp);
	kill(pid, SIGKILL);
	system("leaks pipex");
	return (0);
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
			error("Error\nCheck the cmd and flags");
		i++;
	}
	return (cmd_flags_output);
}

void	parent_process(t_param parameters, int *fd, int *pipe_end, char **envp)
{
	wait(NULL);
	dup2(fd[OUTFILE], STDOUT_FILENO);
	dup2(pipe_end[0], STDIN_FILENO);
	close(pipe_end[1]);
	close(fd[INFILE]);
	if (execve(parameters.correct_path2, parameters.cmd2_flags, envp) == -1)
		error("Error\nExecve issue in the parent");
}

void	child_process(t_param parameters, int *fd, int *pipe_end, char **envp)
{
	dup2(fd[INFILE], STDIN_FILENO);
	dup2(pipe_end[1], STDOUT_FILENO);
	close(pipe_end[0]);
	close(fd[INFILE]);
	if (execve(parameters.correct_path1, parameters.cmd1_flags, envp) == -1)
		error("Error\nExecve issue in the child");
}
