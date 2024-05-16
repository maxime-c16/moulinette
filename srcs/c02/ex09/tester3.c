/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:20 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/14 15:31:18 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	char	str[] = "-test- 1234 5678 90ab cDEf ghiF Klmn opqr stuv MONQ";

	printf("before: %s\n", str);
	ft_strcapitalize(str);
	printf("after: %s\n", str);
	return (0);
}
