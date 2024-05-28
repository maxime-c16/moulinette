/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:49:20 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 15:16:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main()
{
	char			dest[50];
	char			src[50];
	unsigned int	result;
	unsigned int	expected;

	strcpy(dest, "Hello, ");
	strcpy(src, "world!");
	result = ft_strlcat(dest, src, 1);
	expected = strlen("Hello, ") + strlen("world!");

	printf("Expected length: %u, Actual length: %u\n", 7, result);
	printf("Expected first character of dest: \0, Actual first character: %c\n", dest[0]);

	return 0;
}
