/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:02:14 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/12 16:07:06 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

//now test ft_strncpy with strlen(src) < n and strlen(dest) > strlen(src)

void	test_ft_strncpy()
{
	char *src = "Hell";
	char *dest;
	char *ret;
	int i;

	dest = (char *)malloc(sizeof(char) * strlen(src) + 10);
	// bzero(dest, strlen(src) + 10);
	printf("== %s ==\n", __func__);
	ret = ft_strncpy(dest, src, strlen(src) + 5);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("ret: %s\n", ret);
	i = 0;
	while (i < strlen(src))
	{
		if (dest[i] != src[i])
		{
			printf("dest[%d] != src[%d]\n", i, i);
			return ;
		}
		else if (src[i] == '\0')
		{
			printf("Reached end of strings\n");
			return ;
		}
		i++;
	}
	printf("checking for null terminators in the rest of dest\n");
	while (i < strlen(src) + 5)
	{
		if (dest[i] != 0)
		{
			printf("dest[%d] != 0\n", i);
			return ;
		}
		else
			printf("dest[%d] == 0\n", i);
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
