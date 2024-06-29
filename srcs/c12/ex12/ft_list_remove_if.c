/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:19:47 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:09:07 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_top(t_list **begin_list, void *data_ref, int (*cmp) \
	(void *, void *), void (*free_fct)(void *))
{
	t_list	*tmp;

	tmp = NULL;
	while (*begin_list && !(*cmp)((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(tmp->data);
		free(tmp);
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void \
	*, void *), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (!begin_list || !data_ref || !(*cmp) || !(*free_fct))
		return ;
	if (*begin_list)
	{
		ft_list_remove_top(begin_list, data_ref, cmp, free_fct);
		current = *begin_list;
		while (current && current->next)
		{
			if (!(*cmp)(current->next->data, data_ref))
			{
				tmp = current;
				current = current->next;
				tmp->next = tmp->next->next;
				free_fct(current->data);
				free(current);
				current = tmp->next;
			}
			else
				current = current->next;
		}
	}
}
