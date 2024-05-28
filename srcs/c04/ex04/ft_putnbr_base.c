/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:49:02 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:18:05 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	check_base(char *base)
{
	int	i;
	
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	check_duplicate(char *base)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	
	len = 0;
	if (!check_base(base) || !check_duplicate(base))
		return ;
	while (base[len])
		len++;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		ft_putnbr_base(nbr, base);
	}
	else if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	else
		write(1, base + nbr % len, 1);
}
