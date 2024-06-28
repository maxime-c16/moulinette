/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:47:32 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 16:04:44 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list || nbr == 0)
		return (NULL);
	nbr--;
	while (nbr && begin_list)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	if (nbr)
		return (NULL);
	return (begin_list);
}
