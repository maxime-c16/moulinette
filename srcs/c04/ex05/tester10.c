/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:22 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:45:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*base;
	char	*str;
	int		result;

	base = "0123456789ABCDEF";
	str = "            \t\v--++--+-+-2A2A";
	result = ft_atoi_base(str, base);
	printf("Gave: %s\n", str);
	printf("Expected: 10794\n");
	printf("Returned: %d\n", result);
	return (0);
}
