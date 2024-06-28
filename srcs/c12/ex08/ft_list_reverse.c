/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:58:32 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 17:54:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	next = NULL;
	prev = NULL;
	current = *begin_list;
	if (begin_list)
	{
		if (*begin_list)
		{
			while (current)
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			*begin_list = prev;
		}
	}
}


