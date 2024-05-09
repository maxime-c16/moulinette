/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:53:34 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 12:55:55 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fonction ft_putreste qui renvoi le reste de la division par dix ............
int	ft_putreste(int a)
{
	int	reste_div_par_dix;

	reste_div_par_dix = (a % 10) + 48;
	return (reste_div_par_dix);
}

// fonction principale ft_putnbr ..............................................
void	ft_putnbr(int nb)
{
	int	tab[10];
	int	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		tab[i] = ft_putreste(nb);
		nb = nb / 10;
		i++;
	}
	i--;
	nb = nb + 48;
	write(1, &nb, 1);
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
	return ;
}
