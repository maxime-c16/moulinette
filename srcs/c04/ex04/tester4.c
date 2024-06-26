/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:56:14 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:18:50 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "01234567");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "01234567+");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "01234567-");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "01234567 ");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "012345677");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0");
	write(1, "\n", 1);
	return (0);
}
