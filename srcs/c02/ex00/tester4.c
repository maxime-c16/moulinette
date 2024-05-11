/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:09:31 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:37:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*src;
	char	*dst;

	src = "\n\t\0";
	dst = (char *)malloc(sizeof(char) * 3);
	dst = ft_strcpy(dst, src);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	return (0);
}
