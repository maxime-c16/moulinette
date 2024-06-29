/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:15:46 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 14:30:49 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->data = data;
	ptr->next = NULL;
	return (ptr);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(void \
	*, void *))
{
	t_list	*prev;
	t_list	*new;
	t_list	*current;

	prev = NULL;
	new = ft_create_elem(data);
	if (!begin_list || !(*cmp) || !new)
		return ;
	current = *begin_list;
	while (current && (*cmp)(data, current->data) > 0)
	{
		prev = current;
		current = current->next;
	}
	if (!prev)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		prev->next = new;
		new->next = current;
	}
}
