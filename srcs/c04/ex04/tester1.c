/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:54:51 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:19:53 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01234567");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01234567+");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01234567-");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01234567 ");
	write(1, "\n", 1);
	ft_putnbr_base(42, "012345677");
	return (0);
}
