/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:45:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 16:53:41 by mcauchy          ###   ########.fr       */
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

FILE	*get_student_output(char *function_dir, char *function_name)
{
	char	*command;
	char	*stud_path;
	char	*cwd;
	FILE	*student_output;

	cwd = getcwd(NULL, 0);
	cwd = ft_strjoin(cwd, "/");
	stud_path = ft_strjoin(cwd, function_dir);
	command = ft_strjoin("gcc -c ", stud_path);
	command = ft_strjoin(command, function_name);
	command = ft_strjoin(command, ".c ");
	command = ft_strjoin(command, cwd);
	command = ft_strjoin(command, "srcs/");
	command = ft_strjoin(command, function_dir);
	command = ft_strjoin(command, "tester.c");
	printf("command: %s\n", command);
	system(command);
	free(command);
	system("gcc *.o -o stud && ./stud > student_output");
	system("rm *.o");
	student_output = fopen("./student_output", "r");
	return (student_output);
}

int	check_output(FILE *expected_output, FILE *student_output)
{
	char	expected_char;
	char	student_char;

	while (fscanf(expected_output, "%c", &expected_char) != EOF)
	{
		if (fscanf(student_output, "%c", &student_char) == EOF)
		{
			printf("Error: student output is shorter than expected output\n");
			return (EXIT_FAILURE);
		}
		if (expected_char != student_char)
		{
			printf("Error: student output is different from expected output\n");
			return (EXIT_FAILURE);
		}
	}
	if (fscanf(student_output, "%c", &student_char) != EOF)
	{
		printf("Error: student output is longer than expected output\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char **av, char **envp) 
{
	char	*filename;
	char	*function_dir;
	char	*function_name;
	char	*output_dir;
	char	*cwd;
	FILE	*expected_output;
	FILE	*student_output;

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
	
	// output_dir = ft_strjoin("srcs/", function_dir);
	cwd = getcwd(NULL, 0);
	output_dir = ft_strjoin("srcs/", function_dir);
	output_dir = ft_strjoin(output_dir, "output/");
	output_dir = ft_strjoin(output_dir, function_name);
	output_dir = ft_strjoin(output_dir, ".out");
	cwd = ft_strjoin(cwd, "/");
	output_dir = ft_strjoin(cwd, output_dir);
	printf("output_dir: %s\n", output_dir);
	expected_output = fopen(output_dir, "r");
	if (!expected_output)
	{
		printf("Error: could not open expected output file\n");
		return (EXIT_FAILURE);
	}
	student_output = get_student_output(function_dir, function_name);

	if (check_output(expected_output, student_output) == 0)
	{
		//use color code to print OK
		printf("\033[0;32mOK\033[0m\n");
	}
	else
	{
		//use color code to print KO
		printf("\033[0;31mKO\033[0m\n");
	}
	free(filename);
	free(function_name);
	free(function_dir);
	return (EXIT_SUCCESS);
}
