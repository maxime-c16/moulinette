/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:28:02 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			c = a / 10 + '0';
			printf("%c", c);
			c = a % 10 + '0';
			printf("%c", c);
			printf(" ");
			c = b / 10 + '0';
			printf("%c", c);
			c = b % 10 + '0';
			printf("%c", c);
			if (a != 98)
				printf(", ");
			b++;
		}
		a++;
	}
}
