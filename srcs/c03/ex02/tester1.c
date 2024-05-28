/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:17:55 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:27:05 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main(void)
{
	char dest[50] = "Hello";
	char src[50] = " 世界";

	if (strcmp(ft_strcat(dest, src), "Hello 世界") == 0)
		printf("Passed %s\n", dest);
	else
		printf("Failed %s\n", dest);
	return 0;
}
