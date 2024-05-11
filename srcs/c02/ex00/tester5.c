/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:10:40 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

//test strcpy with non printable like 0 through 31

int	main(void)
{
	char	*src;
	char	*dst;
	
	//create the string with char from 0 to 31
	src = (char*)malloc(32);
	for (int i = 0; i < 32; i++)
		src[i] = i;
	src[31] = 0;
	dst = (char*)malloc(32);
	ft_strcpy(dst, src);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	free(src);
	free(dst);
	return (0);
}
