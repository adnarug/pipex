/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:52:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/04 11:37:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define OUTFILE 1
#define INFILE 0
#include "../Printf/ft_printf.h"

typedef struct s_param
{
	char			**cmd1_flags;
	char			**cmd2_flags;
	char			*correct_path1;
	char			*correct_path2;
}	t_param;

char	**find_path(char **envp);
void	print_2d(char **array);
void	sort_params(char **argv, t_param *parameters);
char	**extract_cmd_flags(char *cmd_flags_input);
char	**add_path_sign(char **path_to_builtins);
int		count_strings(char **array);
char	*check_paths(char **path_to_builtins, char	*command);
void	open_files(char *infile_name, char  *outfile_name, int *fd);
void	check_args_validity(int argc, char **argv);
void	init_params(t_param *parameters, char *cmd1_flags, char *cmd2_flags);
void	find_paths(t_param *parameters, char **envp);

#endif