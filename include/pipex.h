/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:52:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/03 13:05:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../Printf/ft_printf.h"

typedef struct s_path
{
	char	*path;
	char	**cmd_path;
	int		pid1;
	int		pid2; 
	int		infile;
	int		outfile;
}	t_path;

typedef struct s_param
{
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
	char			*cmd1;
	char			*correct_path1;
	char			*cmd2;
	char			*correct_path2;
	t_list			*flags1;
	t_list			*flags2;
}	t_param;


char	**find_path(char **envp);
void	print_2d(char **array);
void	sort_params(char **argv, t_param *parameters);
char	**extract_cmd_flags(char *cmd_flags_input, char *cmd);
void	init_params(t_param *parameters, t_list *cmd_flags);
char	**add_path_sign(char **path_to_builtins);
int		count_strings(char **array);
char	*check_paths(char **path_to_builtins, char	*command);
void	open_files(char *infile_name, char  *outfile_name, int *fd);
#endif