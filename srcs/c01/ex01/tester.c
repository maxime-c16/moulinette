/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:49:57 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/10 13:56:38 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	int	a;
	int	*b;
	int	**c;
	int	***d;
	int	****e;
	int	*****f;
	int	******g;
	int	*******h;
	int	********i;
	int	*********j;
	
	a = 0;
	b = &a;
	c = &b;
	d = &c;
	e = &d;
	f = &e;
	g = &f;
	h = &g;
	i = &h;
	j = &i;
	printf("Before: %d\n", a);
	ft_ultimate_ft(j);
	printf("After: %d\n", a);
	return (0);
}
