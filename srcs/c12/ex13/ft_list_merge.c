/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:11:33 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:16:57 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list)
	{
		if (!(begin_list->next))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tail;

	tail = NULL;
	if (!begin_list1 || !begin_list2)
		return ;
	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		tail = ft_list_last(*begin_list1);
		tail->next = begin_list2;
	}
}
