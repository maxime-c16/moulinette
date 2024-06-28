/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:10:14 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 15:18:58 by mcauchy          ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = ft_create_elem(data);
	if (!tmp)
		return ;
	if (begin_list)
	{
		if (*begin_list)
			tmp->next = *begin_list;
		*begin_list = tmp;
	}
	return ;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = 0;
	if (size <= 0 || !strs)
		return (NULL);
	while (i < size)
	{
		ft_list_push_front(&lst, strs[i]);
		i++;
	}
	return (lst);
}
