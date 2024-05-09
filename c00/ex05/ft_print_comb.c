/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:49:02 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 12:51:48 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchars(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7' || b != '8' || c != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 48;
	b = 48;
	c = 48;
	while (a <= 57)
	{	
		while (b <= 57)
		{
			while (c <= 57)
			{
				if (a < b && b < c)
					ft_putchars(a, b, c);
				c++;
			}
			c = 48;
			b++;
		}
	b = 48;
	a++;
	}
}
