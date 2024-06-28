/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:27:29 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/19 15:25:56 by mcauchy          ###   ########.fr       */
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

void	ft_error(char *filename)
{
	ft_putstr_fd(2, basename(filename));
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, strerror(errno));
	ft_putstr_fd(2, "\n");
}

void	ft_putnbr_hex(unsigned int nb, int flag)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 16 && flag == 0)
	{
		write(1, "0", 1);
		write(1, hex + nb, 1);
		return ;
	}
	if (nb > 15)
		ft_putnbr_hex(nb / 16, flag + 1);
	write(1, hex + nb % 16, 1);
}

void	print_hex_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	write(1, "  ", 2);
	while (i < 16 && i < size)
	{
		ft_putnbr_hex(ptr[i], 0);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_address(void *addr)
{
	unsigned long long	address;
	char				*hex;

	hex = "0123456789abcdef";
	if (!addr)
		return ;
	address = (unsigned long long)addr;
	if (address > 15)
		print_address((void *)(address / 16));
	write(1, hex + address % 16, 1);
}

void	print_hex_char(unsigned int num, char *hex)
{
	if (num > 15)
		print_hex_char(num / 16, hex - 1);
	num %= 16;
	if (num < 10)
		*hex = '0' + num;
	else
		*hex = 'a' + num - 10;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	print_offset(unsigned int offset)
{
	char	*hex_offset;

	hex_offset = (char *)malloc(sizeof(char) * 9);
	if (!hex_offset)
		return ;
	hex_offset = ft_strcpy(hex_offset, "00000000");
	print_hex_char(offset, hex_offset + 7);
	write(1, hex_offset, 8);
	free(hex_offset);
}

void	print_char_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)addr;
	write(1, " |", 2);
	while (i < 16 && i < size)
	{
		if (ptr[i] < 32 || ptr[i] > 126)
			write(1, ".", 1);
		else
			write(1, ptr + i, 1);
		i++;
	}
	write(1, "|", 1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int	check_duplicate(unsigned char *buffer, unsigned int size)
{
	int	res;

	res = 0;
	if (size == 0)
		return (-1);
	res = ft_strncmp((char *)buffer, (char *)(buffer - 16), 16);
	if (res == 0)
		return (0);
	return (1);
}

int	ft_hexdump(int fd, unsigned int size)
{
	unsigned int	i;
	unsigned char	*buffer;
	unsigned int	bytes_read;

	i = 0;
	buffer = (unsigned char *)malloc(sizeof(unsigned char) * size);
	bytes_read = read(fd, buffer, size);
	if (!buffer)
		return (0);
	if (bytes_read < 0)
	{
		free(buffer);
		return (0);
	}
	while (i < size)
	{
		if (check_duplicate(buffer + i, i))
		{
			print_offset(i);
			print_hex_line(buffer + i, size - i);
			print_char_line(buffer + i, size - i);
			i += 16;
		}
		else
		{
			write(1, "*", 1);
			while (i < size && !check_duplicate(buffer + i, i))
				i+=16;
		}
		write(1, "\n", 1);
	}
	if (i > size)
	{
		print_offset(size);
		write(1, "\n", 1);
	}
	return (1);
}

unsigned int	ft_filelen(char *filename)
{
	unsigned int	len;
	unsigned int	bytes_read;
	char			buf[4096];
	int				fd;

	len = 0;
	bytes_read = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buf, 4096);
	while (bytes_read > 0)
	{
		len += bytes_read;
		bytes_read = read(fd, buf, 4096);
	}
	close(fd);
	return (len);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;

	fd = 0;
	i = 0;
	if (ac < 3 || av[1][0] != '-' || av[1][1] != 'C')
	{
		ft_putstr_fd(2, "Usage: ./ft_hexdump -C <filename>\n");
		return (1);
	}
	while (ac - i >= 3)
	{
		fd = open(av[2 + i], O_RDONLY);
		if (fd < 0)
		{
			ft_error(av[2 + i]);
			return (1);
		}
		ft_hexdump(fd, ft_filelen(av[2 + i]));
		close(fd);
		i++;
	}
	return (0);
}
