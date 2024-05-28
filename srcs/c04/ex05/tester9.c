/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:05 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:43:42 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*base;
	char	*str;
	int		result;

	base = "0";
	str = "101010";
	result = ft_atoi_base(str, base);
	printf("Gave: %s\n", str);
	printf("Expected: 0\n");
	printf("Returned: %d\n", result);
	return (0);
}
