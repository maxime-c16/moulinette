/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:03 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/24 10:45:49 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

//create a funcrtion that can be used in ft_map

int	ft_add_one(int a)
{
	return (a / 2);
}

int	ft_add_two(int a)
{
	return (a * 2);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		nb += '0';
		write(1, &nb, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void	ft_foreach(int *tab, int lenght, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 10, 42, 2147483647, -2147483648, 0};
	int	*result;

	result = ft_map(tab, 10, &ft_add_one);
	result = ft_map(result, 10, &ft_add_two);
	ft_foreach(result, 10, &ft_putnbr);
	write(1, "\n", 1);
	free(result);
	return (0);
}
