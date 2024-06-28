/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:23 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/29 19:44:46 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	result;

	// result = ft_sqrt(2147395600);
	result = ft_sqrt(2147483647);
	printf("Expected: 46340\n");
	printf("Returned: %d\n", result);
	return (0);
}
