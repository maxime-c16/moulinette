/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:45:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 13:50:14 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	main(void)
{
	t_list	*ptr;

	ptr = ft_create_elem("Hello, World!");
	printf("ptr.data: %s\n", (char *)ptr->data);
	printf("ptr.next: %p\n", (void *)ptr->next);
	return (0);
}
