/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:28:35 by maximecauch       #+#    #+#             */
/*   Updated: 2024/05/14 14:41:16 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	i = 0;
	if (!s1)
		return (0);
	cpy = (char *)ft_calloc(sizeof(char), (strlen(s1) + 1));
	if (!s1 || !cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = (char)s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
