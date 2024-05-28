/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:39:25 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 14:58:48 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main(void)
{
	char *dest;
	char *src = "Hello";

	dest = (char *)malloc(sizeof(char) * 3); // Allocate smaller memory for dest
	printf("strlcpy: %u\n", ft_strlcpy(dest, src, 15));
	printf("src: %s\n", src);
	printf("copying at most %d bytes\n", 15);
	printf("dest: %s\n", dest);
	if (dest[3] == '\0')
		printf("dest[3]: \\0\n");
	else
		printf("dest is not null-terminated\n");
	free(dest); // Free the allocated memory
	return 0;
}
