/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:46:08 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 13:37:48 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	*ft_map(int *tab, int length, int (*funct)(int))
{
	int	i;
	int	*result;

	i = 0;
	if (length <= 0)
		return (0);
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (0);
	while (i < length)
	{
		result[i] = funct(tab[i]);
		i++;
	}
	return (result);
}
