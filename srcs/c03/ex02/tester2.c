/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:19:18 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:27:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main(void)
{
	char dest[50] = "Hello";
	char *src = "";

	if (ft_strcat(dest, src) == dest)
		printf("Passed %s\n", dest);
	else
		printf("Failed%s\n", dest);
	return 0;
}
