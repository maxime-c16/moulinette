/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:29:41 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:30:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "";

	printf("before: %s\n", str);
	ft_strcapitalize(str);
	printf("after: %s\n", str);
	return (0);
}
