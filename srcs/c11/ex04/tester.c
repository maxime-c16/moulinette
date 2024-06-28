/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:35:18 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/27 13:46:43 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	is_sort(int x, int y)
{
	return (x - y);
}

void	print_tab(int *tab, int length)
{
	int	i;

	i = 0;
	printf("tab -> ");
	while (i < length)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	tab[5] = {-5, -2, 0, 42, 77};
	int	tab1[5] = {77, 42, -8, 7, -4};
	int	tab2[5] = {0, 1, 2, 3, -0};

	print_tab(tab, 5);
	printf("%s\n", ft_is_sort(tab, 5, &is_sort) == 1 ? "is sorted" : "unsorted");
	print_tab(tab1, 5);
	printf("%s\n", ft_is_sort(tab1, 5, &is_sort) == 1 ? "is sorted" : "unsorted");
	print_tab(tab2, 5);
	printf("%s\n", ft_is_sort(tab2, 5, &is_sort) == 1 ? "is sorted" : "unsorted");
	return (0);
}
