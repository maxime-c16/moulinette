/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:54:51 by maximecauch       #+#    #+#             */
/*   Updated: 2024/11/22 15:48:48 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r'
			|| *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		if (result > 2147483647 && sign > 0)
			return (-1);
		if (result >= 2147483648 && sign < 0)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)result * sign);
}
