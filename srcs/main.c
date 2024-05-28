/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:45:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 12:42:05 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moulinette.h"

int	g_success_tests = 0;
int	g_total_tests = 0;

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
	system("rm *.o stud");
	student_output = fopen(out_path, "r");
	if (!student_output)
	{
		printf("Error: could not open student output file\n");
		return (NULL);
	}
	return (student_output);
}

int check_output(FILE *expected_output, FILE *student_output, char *output_name, int index)
{
	char	expected_char;
	char	student_char;
	char	*command;
	FILE	*trace;
	bool	is_created = false;

	command = ft_strdup("diff ");
	command = ft_strjoin(command, output_name);
	command = ft_strjoin(command, " student_output");
	command = ft_strjoin(command, ft_itoa(index + 1));
	command = ft_strjoin(command, " >> trace");
	while (fscanf(expected_output, "%c", &expected_char) != EOF)
	{
		if (fscanf(student_output, "%c", &student_char) == EOF)
		{
			if (!is_created)
			{
				trace = fopen("trace", "a");
				if (!trace)
				{
					printf("Error: could not open trace file\n");
					return (EXIT_FAILURE);
				}
				is_created = true;
			}
			system(command);
			fclose(trace);
			return (EXIT_FAILURE);
		}
		if (expected_char != student_char)
		{
			if (!is_created)
			{
				trace = fopen("trace", "a");
				if (!trace)
				{
					printf("Error: could not open trace file\n");
					return (EXIT_FAILURE);
				}
				is_created = true;
			}
			system(command);
			fclose(trace);
			return (EXIT_FAILURE);
		}
	}
	if (fscanf(student_output, "%c", &student_char) != EOF)
	{
		if (!is_created)
		{
			trace = fopen("trace", "a");
			if (!trace)
			{
				printf("Error: could not open trace file\n");
				return (EXIT_FAILURE);
			}
			is_created = true;
		}
		system(command);
		fclose(trace);
		return (EXIT_FAILURE);
	}
	if (is_created)
	{
		fclose(trace);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int return_define_value_from_filename(char *function_name)
{
	struct Function {
		char *name;
		int value;
	};

	struct Function functions[] = {
		{"ft_putchar", FT_PUTCHAR_TESTER},
		{"ft_print_alphabet", FT_PRINT_ALPHABET_TESTER},
		{"ft_print_reverse_alphabet", FT_PRINT_REVERSE_ALPHABET_TESTER},
		{"ft_print_numbers", FT_PRINT_NUMBERS_TESTER},
		{"ft_is_negative", FT_IS_NEGATIVE_TESTER},
		{"ft_print_comb", FT_PRINT_COMB_TESTER},
		{"ft_print_comb2", FT_PRINT_COMB2_TESTER},
		{"ft_putnbr", FT_PUTNBR_TESTER},
		{"ft_print_combn", FT_PRINT_COMBN_TESTER},
		{"ft_ft", FT_FT_TESTER},
		{"ft_ultimate_ft", FT_ULTIMATE_FT_TESTER},
		{"ft_swap", FT_SWAP_TESTER},
		{"ft_div_mod", FT_DIV_MOD_TESTER},
		{"ft_ultimate_div_mod", FT_ULTIMATE_DIV_MOD_TESTER},
		{"ft_putstr", FT_PUTSTR_TESTER},
		{"ft_strlen", FT_STRLEN_TESTER},
		{"ft_rev_int_tab", FT_REV_INT_TAB_TESTER},
		{"ft_sort_int_tab", FT_SORT_INT_TAB_TESTER},
		{"ft_strcpy", FT_STRCPY_TESTER},
		{"ft_strncpy", FT_STRNCPY_TESTER},
		{"ft_str_is_alpha", FT_STR_IS_ALPHA_TESTER},
		{"ft_str_is_numeric", FT_STR_IS_NUMERIC_TESTER},
		{"ft_str_is_lowercase", FT_STR_IS_LOWERCASE_TESTER},
		{"ft_str_is_uppercase", FT_STR_IS_UPPERCASE_TESTER},
		{"ft_str_is_printable", FT_STR_IS_PRINTABLE_TESTER},
		{"ft_strupcase", FT_STRUPCASE_TESTER},
		{"ft_strlowcase", FT_STRLOWCASE_TESTER},
		{"ft_strcapitalize", FT_STRCAPITALIZE_TESTER},
		{"ft_strlcpy", FT_STRLCPY_TESTER},
		{"ft_putstr_non_printable", FT_PUTSTR_NON_PRINTABLE_TESTER},
		{"ft_print_memory", FT_PRINT_MEMORY_TESTER}
		// {"ft_split", FT_SPLIT_TESTER},
		// {"ft_print_tab", FT_PRINT_TAB_TESTER},
		// {"ft_dup_tab", FT_DUP_TAB_TESTER},
		// {"ft_itoa", FT_ITOA_TESTER},
		// {"ft_strmapi", FT_STRMAPI_TESTER},
		// {"ft_strtrim", FT_STRTRIM_TESTER},
		// {"ft_substr", FT_SUBSTR_TESTER},
		// {"ft_strjoin", FT_STRJOIN
	};

	int num_functions = sizeof(functions) / sizeof(functions[0]);

	for (int i = 0; i < num_functions; i++) {
		if (strcmp(function_name, functions[i].name) == 0) {
			return functions[i].value;
		}
	}

	return 0;
}

int	remove_stud_out(int define_v)
{
	int	i;
	char	*command;

	i = 0;
	while (i < define_v)
	{
		command = ft_strdup("rm student_output");
		if (define_v > 1)
			command = ft_strjoin(command, ft_itoa(i + 1));
		system(command);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	create_compare_stud_output(char *function_dir, char *function_name)
{
	char	**output_name;
	char	*cwd;
	int		i;
	int		define_v;
	bool	is_success;
	FILE	**student_outputs;
	FILE	**expected_output;
	int		total_tests;
	int		failed_tests;
	int		successful_tests;
	
	i = 0;
	is_success = true;
	total_tests = 0;
	failed_tests = 0;
	successful_tests = 0;
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
		if (!expected_output[i])
		{
			printf("Error: could not open expected output file\n");
			return (EXIT_FAILURE);
		}
		student_outputs[i] = get_student_output(function_dir, function_name, i, define_v);
		i++;
	}
	i = 0;
	printf("\n----------------------------------\n");
	printf("Now testing \033[0;33m%s\033[0m\n", function_name);
	printf("----------------------------------\n");
	while (i < define_v)
	{
		printf("Test %d: ", i + 1);
		total_tests++;
		if (check_output(expected_output[i], student_outputs[i], output_name[i], i) == 0)
			printf("\033[0;32mOK\033[0m\n");
		else
		{
			printf("\033[0;31mKO\033[0m\n");
			is_success = false;
			failed_tests++;
		}
		usleep(500000);
		i++;
	}
	if (!is_success)
		printf("A trace file has been created at \033[0;33mmoulinette/trace\033[0m\n");
	remove_stud_out(define_v);
	free(output_name);
	free(student_outputs);
	free(expected_output);
	successful_tests = total_tests - failed_tests;
	float grade_percentage = (float)successful_tests / total_tests * 100;
	if (grade_percentage >= 80)
		printf("Grade: \033[1;32m%d / 100\033[0m\n", (int)grade_percentage);
	else if (grade_percentage >= 50)
		printf("Grade: \033[1;33m%d / 100\033[0m\n", (int)grade_percentage);
	else
		printf("Grade: \033[1;31m%d / 100\033[0m\n", (int)grade_percentage);
	printf("----------------------------------\n\n");
	g_success_tests += successful_tests;
	g_total_tests += total_tests;
	return (EXIT_SUCCESS);
}

void process_directory(const char *base_path, const char *sub_dir)
{
	char		path[1024];
	struct		dirent *de;
	DIR			*dr;
	char 		full_path[1024];
	struct stat	st;
	
	snprintf(path, sizeof(path), "%s/%s", base_path, sub_dir);
	dr = opendir(path);
	if (!dr)
	{
		perror("opendir");
		return;
	}
	while ((de = readdir(dr)) != NULL)
	{
		// Skip the current and parent directory entries
		if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
			continue;
		snprintf(full_path, sizeof(full_path), "%s/%s/%s", base_path, sub_dir, de->d_name);
		if (stat(full_path, &st) == -1)
		{
			perror("stat");
			continue;
		}

		if (S_ISDIR(st.st_mode))
			// If it's a directory, recursively process it
			process_directory(base_path, de->d_name);
		else
		{
			// Check if the file name starts with "ft_"
			if (strncmp(de->d_name, "ft_", 3) == 0)
			{
				char new_path[1024];
				snprintf(new_path, sizeof(new_path), "%s/%s/%s", base_path, sub_dir, de->d_name);

				char *filename = strdup(new_path);
				if (!filename)
				{
					perror("strdup");
					continue;
				}
				char *function_dir;
				char *function_name = create_function_name(filename, &function_dir);
				if (!function_name)
				{
					printf("Error: invalid filename\n");
					free(filename);
					continue;
				}
				if (create_compare_stud_output(function_dir, function_name) == EXIT_FAILURE)
				{
					printf("Error: could not create student output\n");
					free(filename);
					free(function_name);
					continue;
				}
				free(filename);
				free(function_name);
				free(function_dir);
			}
		}
	}
	closedir(dr);
}

int main(int ac, char **av) 
{
	float	final_grade;
	
	final_grade = 0;
	if (ac != 2)
	{
		printf("Usage: ./moulinette <CXX>\n");
		return (EXIT_FAILURE);
	}
	system("rm -f trace");
	process_directory(av[1], ".");
	printf("\n----------------------------------\n");
	printf("Final grade: ");
	final_grade = (float)g_success_tests / (float)g_total_tests * 100;
	if (g_success_tests == g_total_tests)
		printf("\033[1;32m%d / 100\033[0m\n", (int)final_grade);
	else if (g_success_tests >= g_total_tests / 2)
		printf("\033[1;33m%d / 100\033[0m\n", (int)final_grade);
	else
		printf("\033[1;31m%d / 100\033[0m\n", (int)final_grade);
	return (EXIT_SUCCESS);
}
