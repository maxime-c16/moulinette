/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:55:15 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/19 15:59:18 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z') && !(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char	*tab[4] = {"salut", "42", "lol", "mdr"};
	char	*tab2[4] = {"0", "1", "2", "3"};

	printf("Is str alpha ?\n");
	if (ft_any(tab, &ft_str_is_alpha))
		printf("true\n");
	else
		printf("false\n");

	printf("Is str alpha ?\n");
	if (ft_any(tab2, &ft_str_is_alpha))
		printf("true\n");
	else
		printf("false\n");
	return (0);
}
