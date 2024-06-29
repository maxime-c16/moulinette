/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:27:13 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:38:41 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_node(t_list *node1, t_list *node2)
{
	t_list	*tmp;

	tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	int		sorted;

	sorted = 0;
	if (!begin_list || !(*begin_list) || !(*cmp))
		return ;
	tmp = *begin_list;
	while (!sorted)
	{
		sorted = 1;
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, tmp->next->data) > 0)
			{
				swap_node(tmp, tmp->next);
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
}
