/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:23 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/16 13:42:29 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	len_dest(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	len;
	int	base_len;

	i = 0;
	len = 0;
	base_len = ft_strlen(base_to);
	while (nbr[i])
	{
		if (is_in_base(nbr[i], base_from) == -1 && nbr[i] != '+' && nbr[i] != '-' && nbr[i] != ' ' && (nbr[i] < 9 || nbr[i] > 13))
			return (0);
		i++;
	}
	i = 0;
	while (nbr[i])
	{
		len = len * ft_strlen(base_from) + is_in_base(nbr[i], base_from);
		i++;
	}
	i = 0;
	while (len)
	{
		len /= base_len;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		i;
	int		j;
	int		base_len;

	i = 0;
	j = 0;
	base_len = ft_strlen(base_to);
	dest = (char *)malloc(sizeof(char) * \
		(len_dest(nbr, base_from, base_to) + 1));
	printf("len dest= %d\n", len_dest(nbr, base_from, base_to));
	if (!dest || !check_base(base_from) || !check_base(base_to) || !nbr || \
		!base_from || !base_to || !len_dest(nbr, base_from, base_to))
		return (NULL);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		dest[j] = base_to[is_in_base(nbr[i], base_from)];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		char	*dest;

		dest = ft_convert_base(av[1], av[2], av[3]);
		if (dest)
		{
			printf("%s", dest);
			free(dest);
		}
	}
	printf("\n");
	return (0);
}
