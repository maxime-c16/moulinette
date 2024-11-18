/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:23:39 by mcauchy           #+#    #+#             */
/*   Updated: 2024/07/08 11:16:56 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_charset_lenw(char *str, char *charset, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (str[i] && charset[i] && str[i] == charset[i])
			i++;
		if (!charset[i])
			return (1);
		return (0);
	}
	else if (flag == 1)
	{
		while (str[i] && !is_charset_lenw(str + i, charset, 0))
			i++;
		return (i);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] != charset[0])
		{
			count++;
			while (str[i] && !is_charset_lenw(str + i, charset, 0))
				i++;
		}
		else
		{
			while (str[i + j] && charset[j] && str[i + j] == charset[j])
				j++;
			if (!charset[j])
				i += j;
			else
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	while (str[i] && is_charset_lenw(str + i, charset, 0))
		i += ft_strlen(charset);
	tab = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	while (str[i])
	{
		if (!is_charset_lenw(str + i, charset, 0))
		{
			k = 0;
			tab[j] = (char *)malloc(is_charset_lenw(str + i, charset, 1) + 1);
			while (str[i] && !is_charset_lenw(str + i, charset, 0))
				tab[j][k++] = str[i++];
			tab[j++][k] = 0;
		}
		else
			i++;
		if (str[i] && is_charset_lenw(str + i, charset, 0))
			i += ft_strlen(charset);
	}
	tab[j] = NULL;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac < 3)
	{
		dprintf(2, "Usage: %s <string> <charset>\n", av[0]);
		return (1);
	}
	tab = ft_split(av[1], av[2]);
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
