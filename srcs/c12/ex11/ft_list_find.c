/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:55:16 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 22:05:14 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, \
	void *))
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (!(*cmp)(tmp->data, data_ref))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
