/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:57:46 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 14:58:02 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*str = "\t\n\v\f\r";
	
	printf("is numeric: %d\n", ft_str_is_numeric(str));
	return (0);
}
