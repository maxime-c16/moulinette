/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:20:21 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 13:32:15 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int ft_strcasecmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (tolower((unsigned char)s1[i]) != tolower((unsigned char)s2[i]))
			return (tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]));
		i++;
	}
	return (tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]));
}

int ft_strlen_cmp(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	return (len1 - len2);
}

int ft_strcmp_reverse(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}

int count_vowels(char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
			*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
		{
			count++;
		}
		str++;
	}
	return count;
}

int ft_vowel_cmp(char *s1, char *s2)
{
	return count_vowels(s1) - count_vowels(s2);
}

void print_tab(char **tab)
{
	int i = 0;
	printf("tab :\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * argc);
	if (!tab)
		return (0);

	for (i = 0; i < argc - 1; i++)
	{
		tab[i] = strdup(argv[i + 1]);
	}
	tab[i] = NULL;

	printf("Before sorting:\n");
	print_tab(tab);

	// Example with ft_strcmp
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	printf("After sorting with ft_strcmp:\n");
	print_tab(tab);

	// Resetting the tab for the next example
	for (i = 0; tab[i] != NULL; i++)
	{
		free(tab[i]);
		tab[i] = strdup(argv[i + 1]);
	}

	// Example with ft_strcasecmp
	ft_advanced_sort_string_tab(tab, &ft_strcasecmp);
	printf("After sorting with ft_strcasecmp:\n");
	print_tab(tab);

	// Clean up
	for (i = 0; tab[i] != NULL; i++)
	{
		free(tab[i]);
		tab[i] = strdup(argv[i + 1]);
	}

	ft_advanced_sort_string_tab(tab, &ft_strlen_cmp);
	printf("After sorting with ft_strlen_cmp:\n");
	print_tab(tab);

	for (i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);

	return 0;
}
