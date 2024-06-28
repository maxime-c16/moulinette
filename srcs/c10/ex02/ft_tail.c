/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:53 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/18 15:05:36 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

int	ft_filelen(char *filename)
{
	int		fd;
	char	buf[4096];
	int		ret;
	int		len;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(basename(filename));
		return (-1);
	}
	ret = read(fd, buf, 4096);
	while (ret > 0)
	{
		len += ret;
		ret = read(fd, buf, 4096);
	}
	close(fd);
	return (len);
}

int	ft_tail(char *filename, int n)
{
	int		fd;
	char	*buff;
	int		ret;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(basename(filename));
		return (-1);
	}
	len = ft_filelen(filename);
	if (len < 0)
		return (-1);
	if (len < n)
		n = len;
	buff = (char *)malloc(sizeof(char) * len);
	if (!buff)
		return (-1);
	ret = read(fd, buff, len);
	if (ret < 0)
	{
		free(buff);
		close(fd);
		return (-1);
	}
	write(1, buff + len - n, n);
	free(buff);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int	nb_bytes;
	int	i;
	int	fd;

	nb_bytes = 0;
	i = 3;
	if (ac < 4)
	{
		ft_putstr_fd("Usage: ./ft_tail -c <bytes> <file1> [file2 ...]\n", 2);
		return (1);
	}
	if (av[1][0] != '-' || av[1][1] != 'c')
	{
		ft_putstr_fd("Usage: ./ft_tail -c <bytes> <file1> [file2 ...]", 2);
		return (1);
	}
	nb_bytes = ft_atoi(av[2]);
	if (nb_bytes < 0)
	{
		ft_putstr_fd("Invalid number of bytes.\n", 2);
		return (1);
	}
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			ft_error(basename(av[i]));
			return (1);
		}
		if (ac > 4)
		{
			ft_putstr_fd("==> ", 1);
			ft_putstr_fd(av[i], 1);
			ft_putstr_fd(" <==\n", 1);
		}
		if (ft_tail(av[i], nb_bytes) < 0)
			ft_error(basename(av[i]));
		close(fd);
		i++;
	}
	return (0);
}
