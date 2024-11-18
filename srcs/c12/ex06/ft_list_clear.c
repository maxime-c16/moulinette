/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:21:13 by mcauchy           #+#    #+#             */
/*   Updated: 2024/07/01 12:28:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_delone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->data);
		free(lst);
	}
}

void	ft_list_clear(t_list *lst, void (*free_fct)(void *))
{
	t_list	*tmp;

	if (!free_fct || !lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		ft_delone(lst, free_fct);
		lst = tmp;
	}
	free(lst);
	lst = NULL;
}
