/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:37:58 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/03 11:57:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_files(char *infile_name, char *outfile_name, int *fd)
{
	
	fd[0] = open(infile_name, O_RDWR, 0777);
	fd[1] = open(outfile_name, O_RDWR, 0777);
	if (fd[0] == -1 || fd[1] == -1)
		return ;
	return ;
}