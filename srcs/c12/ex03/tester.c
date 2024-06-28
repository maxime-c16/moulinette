/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:51:24 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 14:57:21 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

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

void	ft_print_lst(t_list *lst)
{
	printf("List:\n");
	if (!lst)
	{
		printf("(null)\n\n");
		return ;
	}
	printf("head -> ");
	while (lst)
	{
		if (!lst->next)
			printf("[%s] -> (null)\n\n", (char *)lst->data);
		else
			printf("[%s] -> ", (char *)lst->data);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*last;

	lst = NULL;
	ft_print_lst(lst);

	ft_list_push_front(&lst, "third");
	ft_print_lst(lst);
	last = ft_list_last(lst);
	printf("lst.last: [%s]\n\n", (char *)last->data);

	ft_list_push_front(&lst, "second");
	ft_print_lst(lst);
	last = ft_list_last(lst);
	printf("lst.last: [%s]\n\n", (char *)last->data);

	ft_list_push_front(&lst, "first");
	ft_print_lst(lst);
	last = ft_list_last(lst);
	printf("lst.last: [%s]\n\n", (char *)last->data);

	return (0);
}
