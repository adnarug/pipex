/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:52:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/29 17:49:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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
	char			*command;
	t_list			*flags;
}	t_param;


char	**find_path(char **envp);
void	print_2d(char **array);
void	sort_params(char **argv, t_param *parameters);
void	extract_cmd_flags(char *commands_flags, t_param *parameters);
void	sort_params(char **argv, t_param *parameters);
void	init_params(t_param *parameters, t_list *cmd_flags);
char	*check_paths(char** path_to_check, t_param *parameters);

#endif