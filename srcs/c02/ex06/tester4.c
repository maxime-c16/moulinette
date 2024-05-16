/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:04:43 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:17:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "HELLO";

	printf("is printable: %d\n", ft_str_is_printable(str));
	return (0);
}
