/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:46:19 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	tab[0];
	int	size;
	int	i;

	size = 0;
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
