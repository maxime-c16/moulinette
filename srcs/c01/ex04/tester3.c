/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:23:03 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	div;
	int	mod;	

	div = 10;
	mod = 2;
	ft_ultimate_div_mod(&div, &mod);
	printf("div: %d, mod: %d\n", div, mod);
	return (0);
}
