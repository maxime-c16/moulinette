/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:31:58 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:32:48 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*base;
	char	*str;
	int		result;

	base = "0123456789abcdef";
	str = "2a";
	result = ft_atoi_base(str, base);
	printf("Gave: %s\n", str);
	printf("Expected: 42\n");
	printf("Returned: %d\n", result);
	return (0);
}
