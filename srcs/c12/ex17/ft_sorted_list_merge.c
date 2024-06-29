/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:07:37 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 18:55:14 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert_if(t_list **lst, t_list *elem, \
	int (*cmp)(void *, void *))
{
	if (!(*lst) || (*cmp)(elem->data, (*lst)->data) <= 0)
	{
		elem->next = (*lst);
		(*lst) = elem;
	}
	else
		ft_sorted_list_insert_if(&(*lst)->next, elem, (*cmp));
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
	int (*cmp)(void *, void *))
{
	if (!begin_list2)
		return ;
	ft_sorted_list_merge(begin_list1, begin_list2->next, (*cmp));
	ft_sorted_list_insert_if(begin_list1, begin_list2, (*cmp));
}
