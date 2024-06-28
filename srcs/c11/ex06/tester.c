/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:02:54 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 13:07:28 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	printf("tab :\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * ac);
	if (!tab)
		return (0);
	while (i < ac - 1)
	{
		tab[i] = strdup(av[i + 1]);
		i++;
	}
	tab[i] = NULL;
	print_tab(tab);
	ft_sort_string_tab(tab);
	print_tab(tab);
	return (0);
}
