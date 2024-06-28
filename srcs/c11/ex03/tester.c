/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:12:34 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/27 13:47:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	ft_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_alpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_numeric(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	for (int i = 0; str[i]; i++)
		len++;
	return len;
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int	main(void)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 3);
	if (!tab)
		return (1);
	tab[0] = ft_strdup("test");
	tab[1] = ft_strdup("01234");
	tab[2] = ft_strdup("TEST");
	printf("0: %s, 1: %s, 2: %s\n", tab[0], tab[1], tab[2]);
	printf("str_is_alpha : %d\n", ft_count_if(tab, 3, &ft_str_is_alpha));
	printf("str_is_numeric : %d\n", ft_count_if(tab, 3, &ft_str_is_numeric));
	free(tab);
	return 0;
}
