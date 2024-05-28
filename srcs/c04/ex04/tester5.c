/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:57:38 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:06:14 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	ft_putnbr_base(2147483647, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01234567");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01234567+");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01234567-");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "01234567 ");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "012345677");
	write(1, "\n", 1);
	ft_putnbr_base(2147483647, "0");
	write(1, "\n", 1);
	return (0);
}
