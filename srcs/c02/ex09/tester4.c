/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:31:32 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:32:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "\t\n\v\f\r 012345678 9abcd efghijklmnopqrstuvwx yzABCDEFGHIJKLMNOPQRSTUVWXYZ{";

	printf("before: %s\n", str);
	ft_strcapitalize(str);
	printf("after: %s\n", str);
	return (0);
}
