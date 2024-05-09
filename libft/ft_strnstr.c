/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:28:14 by maximecauch       #+#    #+#             */
/*   Updated: 2022/06/22 12:21:04 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	int		j;
	char	*ptr;

	i = 0;
	ptr = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[0])
		{
			ptr = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < n)
			{
				if (needle[j + 1] == '\0')
					return (ptr);
				j++;
			}
			ptr = 0;
		}
		i++;
	}
	return (NULL);
}
