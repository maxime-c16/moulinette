/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:52:00 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 13:52:10 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	*str = "Wor worlHello Wo World";
	
	printf("%s\n", ft_strstr(str, "orl"));
	return (0);
}
