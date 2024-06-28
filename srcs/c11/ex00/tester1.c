/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:21 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/19 15:40:26 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

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

void	ft_putnbr_hex(int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, "0", 1);
		write(1, hex + nb, 1);
		return ;
	}
	ft_putnbr_hex(nb / 16);
	write(1, hex + nb % 16, 1);
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 10, 42, 2147483647, -2147483648, 0};

	ft_foreach(tab, 10, &ft_putnbr);
	write(1, "\n", 1);
	ft_foreach(tab, 10, &ft_putnbr_hex);
	write(1, "\n", 1);
	return (0);
}
