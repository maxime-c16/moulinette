/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:55:15 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:00:04 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*s1 = "\tHe";
	char	*s2 = "\tHe";
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
