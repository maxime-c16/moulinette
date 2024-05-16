/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:13:57 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:14:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "HELLO WORLD";

	printf("before: %s\n", str);
	ft_strupcase(str);
	printf("after: %s\n", str);
	return (0);
}
