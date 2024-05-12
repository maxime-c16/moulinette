/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:00:09 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/12 16:07:23 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

//now test ft_strncpy with n = 0

void	test_ft_strncpy()
{
	char *src = "Hello, World!";
	char *dest;
	char *ret;
	int i;

	dest = (char *)malloc(sizeof(char) * strlen(src) + 1);
	// bzero(dest, strlen(src) + 1);
	printf("== %s ==\n", __func__);
	ret = ft_strncpy(dest, src, 0);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("ret: %s\n", ret);
	i = 0;
	if (dest[0] != 0)
	{
		printf("dest[0] != 0\n");
		return ;
	}
	printf("OK\n");
	free(dest);
}

int		main()
{
	test_ft_strncpy();
	return (0);
}
