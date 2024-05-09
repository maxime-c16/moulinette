/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:19:55 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 14:21:57 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	int_max;
	int	int_min;
	
	int_max = 2147483647;
	int_min = -2147483648;
	ft_is_negative(int_max);
	ft_is_negative(int_min);
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(1);
	return (0);
}
