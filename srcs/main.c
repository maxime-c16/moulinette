/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:45:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 15:19:18 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this project aims to correct some exercises drom the piscine c of 42
it will take the filename as follow: ./moulinette <CXX/exXX/ft_XXX.c>
then it will get the fubnction that main_tester of that exercise and run the tests
the it will compare the output with the expected output
*/

#include "../includes/moulinette.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*create_function_name(char *filename, char **function_dir) 
{
	int		index;
	int		i;
	int		slash_count;
	int		size;
	char	*buff;
	char	*dir_cpy;
	
	i = 0;
	index = 0;
	size = 0;
	slash_count = 0;
	dir_cpy = *function_dir;
	while (filename[index])
	{
		if (filename[index] == '/')
			slash_count++;
		if (slash_count == 2)
		{
			index++;
			dir_cpy = (char *)malloc(sizeof(char) * index + 1);
			while (i < index)
			{
				dir_cpy[i] = filename[i];
				i++;
			}
			dir_cpy[index] = 0;
			*function_dir = dir_cpy;
			while (filename[index] != '.' && filename[index])
			{
				size++;
				index++;
			}
			if (filename[index] == 0)
				return (NULL);
			buff = (char *)malloc(sizeof(char) * size + 1);
			index -= size;
			size = index;
			while (filename[index] != '.' && filename[index])
			{
				buff[index - size] = filename[index];
				index++;
			}
			buff[index - size] = 0;
			return (buff);
		}
		index++;
	}
	if (slash_count < 2)
		return (NULL);
	return (NULL);
}

int main(int ac, char **av) 
{
	char	*filename;
	char	*function_dir;
	char	*function_name;
	char	*expected_output;

	if (ac != 2) {
		printf("Usage: ./moulinette <CXX/exXX/ft_XXX.c>\n");
		return (EXIT_FAILURE);
	}
	filename = strdup(av[1]);
	function_name = create_function_name(filename, &function_dir);
	if (!function_name)
	{
		printf("Error: invalid filename\n");
		return (EXIT_FAILURE);
	}
	printf("filename: %s\n", filename);
	printf("function_name: %s\n", function_name);
	printf("function_dir: %s\n", function_dir);
	
	// expected_output = get_expected_output(filename, function_name);

	free(filename);
	free(function_name);
	free(function_dir);
	return (EXIT_SUCCESS);
}
