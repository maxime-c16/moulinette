/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:58 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:43:36 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*base;
	char	*str;
	int		result;

	base = "+- \t\v\f\r\n0123456789abcdef";
	str = "101010";
	result = ft_atoi_base(str, base);
	printf("Gave: %s\n", str);
	printf("Expected: 0\n");
	printf("Returned: %d\n", result);
	return (0);
}
