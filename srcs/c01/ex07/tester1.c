/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:36:17 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/10 14:39:28 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};
	int	size;
	int	i;
	
	i = 0;
	size = 5;
	printf("before: ");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	i = 0;
	ft_rev_int_tab(tab, size);
	printf("\nafter: ");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
