/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:39:46 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 12:44:04 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	tab[0];
	int	size;
	int	i;
	
	i = 0;
	size = 0;
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
