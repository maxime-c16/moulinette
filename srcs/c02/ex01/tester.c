/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:25:44 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	test_ft_strncpy()
{
	char *src = "Hello, World!";
	char dest[100];
	char *ret;
	int i;

	printf("== %s ==\n", __func__);
	ret = ft_strncpy(dest, src, 5);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("ret: %s\n", ret);
	i = 0;
	while (i < 5)
	{
		if (dest[i] != src[i])
		{
			printf("dest[%d] != src[%d]\n", i, i);
			return ;
		}
		i++;
	}
	printf("OK\n");
}

int		main()
{
	test_ft_strncpy();
	return (0);
}
