/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:42:40 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/10 14:48:18 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	tab[12] = {18, 5, 42, -5, 18, 18, 0, 0, 0, 0, -2147483648, 2147483647};
	int	size;
	int	i;

	size = 12;
	i = 0;
	printf("before: ");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	i = 0;
	printf("\nafter: ");
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
