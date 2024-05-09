/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:04:20 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/09 14:04:36 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_print_reverse_alphabet(void)
{
	char c;

	c = 'z';
	while (c >= 'a')
	{
		printf("%c", c);
		c--;
	}
}
