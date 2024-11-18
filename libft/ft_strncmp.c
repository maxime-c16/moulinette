/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:58:51 by maximecauch       #+#    #+#             */
/*   Updated: 2024/11/18 12:16:46 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!s1)
		return (0);
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
