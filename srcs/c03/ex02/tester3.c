/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:20:31 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:26:05 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main()
{
	char dest[10000] = "Hello";
	char src[10000] = " World";
	char	*ret = malloc(10000);
	for (int i = 0; i < 999; i++) {
		ret = ft_strcat(dest, src);
	}
	printf("%s\n", dest);
	return 0;
}
