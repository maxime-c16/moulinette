/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:54:31 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:00:04 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = "Hell";
	int		result;

	result = ft_strcmp(s1, s2);
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
