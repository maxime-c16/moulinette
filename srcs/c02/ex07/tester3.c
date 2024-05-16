/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:12:49 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:13:02 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "hello, WORLD!";

	printf("before: %s\n", str);
	ft_strupcase(str);
	printf("after: %s\n", str);
	return (0);
}
