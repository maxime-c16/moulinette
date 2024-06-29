/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:26:14 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 22:03:47 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void \
	*data_ref, int (*cmp)(void *, void *))
{
	if (begin_list)
	{
		while (begin_list)
		{
			if (!(*cmp)(begin_list->data, data_ref))
				(*f)(begin_list->data);
			begin_list = begin_list->next;
		}
	}
}
