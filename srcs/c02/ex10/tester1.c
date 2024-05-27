/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:34:19 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/23 14:12:42 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*dest;
	char	*src = "Hello";
	
	dest = (char *)malloc(sizeof(char) * sizeof(src) + 1);
	printf("strlcpy: %lu\n", strlcpy(dest, src, 3));
	printf("copying at most %d bytes\n", 3);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	if (dest[3] == '\0')
		printf("dest[3]: \\0\n");
	else
		printf("dest[3]: %c\n", dest[3]);
	if (dest[sizeof(src)] == '\0')
		printf("dest[%lu]: \\0\n", sizeof(src));
	else
		printf("dest is not null-terminated\n");
	free(dest);
	return (0);
}
