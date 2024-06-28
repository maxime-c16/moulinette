/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:39:04 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/19 15:44:06 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_multiply(int a)
{
	a *= 2;
}

void	ft_add(int a)
{
	a += 1;
}

void	ft_subtract(int a)
{
	a -= 1;
}

void	ft_divide(int a)
{
	a /= 2;
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 10, 42, 2147483647, -2147483648, 0};

	ft_foreach(tab, 10, &ft_multiply);
	ft_foreach(tab, 10, &ft_add);
	ft_foreach(tab, 10, &ft_subtract);
	ft_foreach(tab, 10, &ft_divide);
	printf("done\n");
	write(1, "\n", 1);
	return (0);
}
