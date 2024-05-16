/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:16:16 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:16:24 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "123456";

	printf("before: %s\n", str);
	ft_strlowcase(str);
	printf("after: %s\n", str);
	return (0);
}
