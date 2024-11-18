/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:45:57 by mcauchy           #+#    #+#             */
/*   Updated: 2024/07/02 10:56:54 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(int ac, char **av)
{
	char	*str;

	// str = ft_strjoin(ac, av, NULL);
	// str = ft_strjoin(ac, NULL, "test");
	str = ft_strjoin(0, NULL, "test");
	str = ft_strjoin(ac, av, " et ");
	printf("%s\n", str);
}
