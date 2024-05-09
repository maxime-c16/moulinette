/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:40:39 by mcauchy           #+#    #+#             */
/*   Updated: 2022/08/28 12:41:41 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *str, char *old_str)
{
	int	i;

	i = 0;
	while (old_str[i])
	{
		str[i] = old_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
