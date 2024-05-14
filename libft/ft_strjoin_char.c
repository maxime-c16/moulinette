/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:36:56 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 14:41:16 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (strlen(str) + 2));
	if (!new_str)
		return (NULL);
	new_str = ft_strcpy(new_str, str);
	new_str[strlen(str)] = c;
	new_str[strlen(str) + 1] = '\0';
	if (str)
		free(str);
	return (new_str);
}
