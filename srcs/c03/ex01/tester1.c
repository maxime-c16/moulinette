/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:05:34 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:05:46 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = "Hello";
	int		result;

	result = ft_strncmp(s1, s2, 5);
	if (result == 0)
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("Strings are different\n");
	}
	return (0);
}
