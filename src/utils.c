/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/29 17:12:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int count_strings(char **array);

int count_strings(char **array)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while (array[i] != NULL)
	{
		i++;
		counter++;
	}
	return (counter);
}

void	print_2d(char **array)
{
	if (array == NULL)
		return ;
	int	x;
	int	y;
	int line_count;

	x = 0;
	y = 0;
	line_count = count_strings(array);

	while(y < line_count && array[y] != NULL)
	{
		while(array[y][x] != '\0')
		{
			printf("%c", array[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}
