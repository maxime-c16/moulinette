/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:19 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 14:43:08 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_print_combn(int n)
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int o;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	o = 0;
	while (i <= 9)
	{
		while (j <= 9)
		{
			while (k <= 9)
			{
				while (l <= 9)
				{
					while (m <= 9)
					{
						while (o <= 9)
						{
							if (i < j && j < k && k < l && l < m && m < o)
							{
								if (n == 1)
									printf("%d", i);
								if (n == 2)
									printf("%d%d", i, j);
								if (n == 3)
									printf("%d%d%d", i, j, k);
								if (n == 4)
									printf("%d%d%d%d", i, j, k, l);
								if (n == 5)
									printf("%d%d%d%d%d", i, j, k, l, m);
								if (n == 6)
									printf("%d%d%d%d%d%d", i, j, k, l, m, o);
								if (i != 4 || j != 5 || k != 6 || l != 7 || m != 8 || o != 9)
									printf(", ");
							}
							o++;
						}
						o = 0;
						m++;
					}
					m = 0;
					l++;
				}
				l = 0;
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
