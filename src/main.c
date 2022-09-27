/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/27 16:33:13 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char** argv, char** envp)
{
	if (envp == NULL || *envp == NULL)
		return (0);
	//Search for the path variable in path
		//strncmp or smth else looking for PATH=
	//Struct
		//to keep the path, pid1, pid2, cmd_path
	
	
	// int	f;
	
	// // f = fork();
	// // if (f == 0)
	// // {
	// // 		printf("Hello World!");
	// // }
	// // if (f != 0)
	// // {
	// // 		printf("%s\n", envp);
	// // }
	return (0);
}