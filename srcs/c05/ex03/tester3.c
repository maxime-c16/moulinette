/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:18:23 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/29 18:54:22 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	result;

	result = ft_recursive_power(5, -3);
	printf("Expected: 0\n");
	printf("Returned: %d\n", result);
	return (0);
}
