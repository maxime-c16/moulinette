/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:20:25 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/17 20:32:43 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	ft_putstr_fd(int fd, char *str)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

void	ft_display_file(char *filename)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return ;
	}
	ret = read(fd, buffer, BUFF_SIZE);
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, BUFF_SIZE);
	}
	close(fd);
	return ;
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	else if (ac > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	else
		ft_display_file(av[1]);
	return (0);
}
