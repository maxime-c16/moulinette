/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:49:46 by mcauchy           #+#    #+#             */
/*   Updated: 2024/11/18 17:05:41 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*str = "Hello World";

	printf("Testing : ft_strstr(\"%s\", \"\")\n", str);
	printf("%s\n", ft_strstr(str, ""));
	printf("Expected : Hello World\n");
	return (0);
}
