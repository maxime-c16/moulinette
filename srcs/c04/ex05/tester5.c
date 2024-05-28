/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:36:28 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:43:21 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*base;
	char	*str;
	int		result;

	base = "abc";
	str = "caca";
	result = ft_atoi_base(str, base);
	printf("Gave: %s\n", str);
	printf("Expected: 60\n");
	printf("Returned: %d\n", result);
	return (0);
}
