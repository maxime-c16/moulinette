/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:56:48 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 13:37:26 by mcauchy          ###   ########.fr       */
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

void	ft_putnbr(int nb)
{
	char	res;

	res = 0;
	if (nb == -2147483647)
	{
		write(1, "-2147483647", 12);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		res = nb + '0';
		write(1, &res, 1);
	}
}

int	check_tab_len(char **tab, int length)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i < length)
	{
		if (!ft_strlen(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_operand(char c)
{
	int		i;
	char	*operands;

	i = 0;
	operands = "+-/*%";
	while (operands[i])
	{
		if (c == operands[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	*map(char c, int error)
{
	if (c == '+')
		return (&add);
	else if (c == '-')
		return (&sub);
	else if (c == '/')
	{
		if (error)
			return (&divi);
		write(1, "Stop : division by zero\n", 25);
		return (NULL);
	}
	else if (c == '*')
		return (&mul);
	else if (c == '%')
	{
		if (error)
			return (&mod);
		write(1, "Stop : modulo by zero\n", 23);
		return (NULL);
	}
	else
		return (NULL);
}

int	do_op(int op1, int op2, int (*f)(int, int))
{
	return (f(op1, op2));
}

int	main(int ac, char **av)
{
	void	*function;

	function = NULL;
	if (ac < 4 || ac > 4)
		return (0);
	if (!check_tab_len(av, ac) || av[2][1] || !is_operand(av[2][0]))
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	function = map(av[2][0], ft_atoi(av[3]));
	if (!function)
		return (0);
	ft_putnbr(do_op(ft_atoi(av[1]), ft_atoi(av[3]), function));
	write(1, "\n", 1);
	return (0);
}
