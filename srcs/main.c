/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:45:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/10 10:45:46 by mcauchy          ###   ########.fr       */
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

FILE	*get_student_output(char *function_dir, char *function_name, int index, int define_v)
{
	char	*command;
	char	*stud_path;
	char	*cwd;
	char	*out_path;
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
	if (define_v > 1)
	{
		command = ft_strjoin(command, "tester");
		command = ft_strjoin(command, ft_itoa(index + 1));
		out_path = ft_strjoin("student_output", ft_itoa(index + 1));
	}
	else
	{
		command = ft_strjoin(command, "tester");
		out_path = ft_strdup("student_output");
	}
	command = ft_strjoin(command, ".c");
	system(command);
	free(command);
	command = ft_strdup("gcc *.o -o stud && ./stud > ");
	command = ft_strjoin(command, out_path);
	system(command);
	system("rm *.o");
	student_output = fopen(out_path, "r");
	if (!student_output)
	{
		printf("Error: could not open student output file\n");
		return (NULL);
	}
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

int	return_define_value_from_filename(char *function_name)
{
	if (strcmp(function_name, "ft_putchar") == 0)
		return (FT_PUTCHAR_TESTER);
	if (strcmp(function_name, "ft_print_alphabet") == 0)
		return (FT_PRINT_ALPHABET_TESTER);
	if (strcmp(function_name, "ft_print_reverse_alphabet") == 0)
		return (FT_PRINT_REVERSE_ALPHABET_TESTER);
	if (strcmp(function_name, "ft_print_numbers") == 0)
		return (FT_PRINT_NUMBERS_TESTER);
	if (strcmp(function_name, "ft_is_negative") == 0)
		return (FT_IS_NEGATIVE_TESTER);
	if (strcmp(function_name, "ft_print_comb") == 0)
		return (FT_PRINT_COMB_TESTER);
	if (strcmp(function_name, "ft_print_comb2") == 0)
		return (FT_PRINT_COMB2_TESTER);
	if (strcmp(function_name, "ft_putnbr") == 0)
		return (FT_PUTNBR_TESTER);
	if (strcmp(function_name, "ft_print_combn") == 0)
		return (FT_PRINT_COMBN_TESTER);
	return (0);

}

int	create_compare_stud_output(char *function_dir, char *function_name)
{
	char	**output_name;
	char	*cwd;
	int		i;
	int		define_v;
	FILE	**student_outputs;
	FILE	**expected_output;
	
	i = 0;
	define_v = return_define_value_from_filename(function_name);
	output_name = (char **)malloc(sizeof(char *) * define_v + 1);
	student_outputs = (FILE **)malloc(sizeof(FILE *) * define_v + 1);
	expected_output = (FILE **)malloc(sizeof(FILE *) * define_v + 1);
	if (!output_name || !student_outputs || !expected_output)
		return (EXIT_FAILURE);
	cwd = getcwd(NULL, 0);
	while (i < define_v)
	{
		output_name[i] = ft_strjoin("srcs/", function_dir);
		output_name[i] = ft_strjoin(output_name[i], "output/");
		output_name[i] = ft_strjoin(output_name[i], function_name);
		if (define_v > 1)
			output_name[i] = ft_strjoin(output_name[i], ft_itoa(i + 1));
		output_name[i] = ft_strjoin(output_name[i], ".out");
		cwd = ft_strjoin(cwd, "/");
		output_name[i] = ft_strjoin(cwd, output_name[i]);
		expected_output[i] = fopen(output_name[i], "r");
		printf("Opening expected output file %s\n", output_name[i]);
		if (!expected_output[i])
		{
			printf("Error: could not open expected output file\n");
			return (EXIT_FAILURE);
		}
		student_outputs[i] = get_student_output(function_dir, function_name, i, define_v);
		i++;
	}
	i = 0;
	printf("Now comparing the outputs\n");
	while (i < define_v)
	{
		printf("Test %d: ", i);
		if (check_output(expected_output[i], student_outputs[i]) == 0)
			printf("\033[0;32mOK\033[0m\n");
		else
			printf("\033[0;31mKO\033[0m\n");
		i++;
	}
	free(output_name);
	free(student_outputs);
	free(expected_output);
	return (EXIT_SUCCESS);
}

int main(int ac, char **av, char **envp) 
{
	char	*filename;
	char	*function_dir;
	char	*function_name;

	if (ac != 2)
	{
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
	if (create_compare_stud_output(function_dir, function_name) == EXIT_FAILURE)
	{
		free(filename);
		free(function_name);
		free(function_dir);
		return (EXIT_FAILURE);
	}
	free(filename);
	free(function_name);
	free(function_dir);
	return (EXIT_SUCCESS);
}
