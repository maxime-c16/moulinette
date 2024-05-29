/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:16:54 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/29 14:21:40 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	result;
	
	result = ft_recursive_power(5, 3);
	printf("Expected: 125\n");
	printf("Returned: %d\n", result);
	return (0);
}
