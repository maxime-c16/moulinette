/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:06:46 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:08:47 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*s1 = "Hello\t";
	char	*s2 = "Hello";
	int		result;

	result = ft_strncmp(s1, s2, 10);
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
