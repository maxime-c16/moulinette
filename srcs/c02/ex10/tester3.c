/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 14:58:51 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*dest;
	char	*src = "Hello";
	
	dest = (char *)malloc(sizeof(char) * sizeof(src) + 1);
	dest = strdup("1234");
	printf("strlcpy: %u\n", ft_strlcpy(dest, src, 1));
	printf("src: %s\n", src);
	printf("copying at most %d bytes\n", 1);
	printf("dest: %s\n", dest);
	if (dest[1] == '\0')
		printf("dest[1]: \\0\n");
	else
		printf("dest is not null-terminated\n");
	free(dest);
	return (0);
}
