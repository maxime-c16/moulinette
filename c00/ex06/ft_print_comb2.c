/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:51:56 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 12:53:25 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	print(int nb)
{
	char	a;
	char	b;

	a = (nb / 10) + 48;
	b = (nb % 10) + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	return (0);
}

int	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			print(a);
			write(1, " ", 1);
			print(b);
			write(1, ", ", 2);
			b++;
		}
		a++;
		b = a + 1;
	}
	return (0);
}
