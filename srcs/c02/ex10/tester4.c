/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:51:54 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/16 18:11:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int main(void)
{
	char src[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F\x20";
	char *dest;
	size_t dest_size = sizeof(src);
	dest = (char *)malloc(sizeof(char) * dest_size + 1);
	size_t result = ft_strlcpy(dest, src, dest_size);
	printf("copying at most %zu bytes\n", dest_size);
	printf("src: %s\n", src);
	printf("Result: %zu\n", result);
	printf("Destination: %s\n", dest);
	if (dest[dest_size - 1] == '\0')
		printf("dest[%zu]: \\0\n", dest_size - 1);
	else
		printf("dest is not null-terminated\n");
}
