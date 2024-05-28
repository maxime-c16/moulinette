/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:07:16 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 15:10:56 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char			str[50] = "test";
	char			dest[50] = " passed :)";
	unsigned int	res = 0;
	
	res = ft_strlcat(str, dest, 30);
	printf("Result: %s\n", str);
	printf("Return: %u\n", res);
	return (0);
}
