/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:20:10 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/27 20:22:47 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			hex[0] = "0123456789abcdef"[str[i] / 16];
			hex[1] = "0123456789abcdef"[str[i] % 16];
			write(1, "\\", 1);
			write(1, hex, 2);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
