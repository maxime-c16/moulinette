/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:11:27 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/10 14:13:06 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	int_max;
	int	int_min;
	int	div;
	int	mod;	

	int_max = 10;
	int_min = -2;
	ft_div_mod(int_max, int_min, &div, &mod);
	printf("div: %d, mod: %d\n", div, mod);
	return (0);
}

