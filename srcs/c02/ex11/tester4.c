/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:27:10 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/27 20:31:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "\a\b\t\n\v\f\r\x1B\x1C\x1D\x1E\x1F\x7F";
	
	ft_putstr_non_printable(str);
	return (0);
}
