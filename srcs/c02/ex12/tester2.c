/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:44:01 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/27 20:50:23 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main(void)
{
	char *str = "This is a test string.";
	int arr[] = {1, 2, 3, 4, 5};
	float f = 3.14;
	double d = 2.71828;
	int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	ft_print_memory(str, strlen(str));
	ft_print_memory(arr, sizeof(arr));
	ft_print_memory(&f, sizeof(f));
	ft_print_memory(&d, sizeof(d));
	ft_print_memory(matrix, sizeof(matrix));

	return 0;
}
