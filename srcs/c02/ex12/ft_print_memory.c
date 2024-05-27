/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:36:15 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/27 20:55:30 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	print_hex_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < 16 && i < size)
	{
		ft_print_hex(ptr[i]);
		if (i % 2)
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

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, hex + c / 16, 1);
	write(1, hex + c % 16, 1);
}

void	print_char_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < 16 && i < size)
	{
		if (ptr[i] < 32 || ptr[i] > 126)
			write(1, ".", 1);
		else
			write(1, ptr + i, 1);
		i++;
	}
}

void	print_address(void *addr)
{
	unsigned long long	address;
	char				*hex;

	address = (unsigned long long)addr;
	hex = "0123456789abcdef";
	if (address > 15)
		print_address((void *)(address / 16));
	write(1, hex + address % 16, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!addr)
		return (addr);
	while (i < size)
	{
		print_address(addr + i);
		write(1, ": ", 2);
		print_hex_line(addr + i, size - i);
		print_char_line(addr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
