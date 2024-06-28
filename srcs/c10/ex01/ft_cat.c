/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:08:04 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/17 20:12:29 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

void	ft_cat(char *filename)
{
	int		fd;
	char	buf[4096];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(basename(filename));
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return ;
	}
	while ((ret = read(fd, buf, 4096)) > 0)
		write(1, buf, ret);
	close(fd);
	return ;
}

int	main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
	{
		ft_cat("/dev/stdin");
		return (0);
	}
	while (i < ac)
	{
		ft_cat(av[i]);
		i++;
	}
	return (0);
}
