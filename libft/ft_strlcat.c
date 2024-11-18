/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:43:47 by mcauchy           #+#    #+#             */
/*   Updated: 2024/11/18 12:23:55 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = strlen(src);
	dest_length = strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}
