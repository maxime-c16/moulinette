/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:25 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:59:24 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	next = NULL;
	prev = NULL;
	current = begin_list;
	if (begin_list)
	{
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
	}
}
