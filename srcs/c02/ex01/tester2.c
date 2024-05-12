/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:55:25 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/12 15:59:49 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	test_ft_strncpy()
{
	char *src = "Hello, World!";
	char *dest;
	char *ret;
	int i;

	dest = (char *)malloc(sizeof(char) * strlen(src) + 1);
	printf("== %s ==\n", __func__);
	ret = ft_strncpy(dest, src, 20);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("ret: %s\n", ret);
	i = 0;
	while (i < 20)
	{
		if (dest[i] != src[i])
		{
			printf("dest[%d] != src[%d]\n", i, i);
			return;
		}
		else if (dest[i] == '\0' || src[i] == '\0')
		{
			printf("Reached end of strings\n");
			return;
		}
		i++;
	}
	printf("OK\n");
	free(dest);
}

int		main()
{
	test_ft_strncpy();
	return (0);
}
