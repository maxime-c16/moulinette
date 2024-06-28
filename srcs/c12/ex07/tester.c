/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:54:29 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 16:05:25 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

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

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list)
	{
		if (!(begin_list->next))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*new;

	last = NULL;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (begin_list)
	{
		if (*begin_list)
		{
			last = ft_list_last(*begin_list);
			last->next = new;
		}
		else
			*begin_list = new;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*elem;

	elem = NULL;
	lst = NULL;
	ft_print_lst(lst);

	ft_list_push_back(&lst, "First");
	ft_list_push_back(&lst, "Second");
	ft_list_push_back(&lst, "Third");
	ft_list_push_back(&lst, "Fourth");
	ft_list_push_back(&lst, "Fifth");
	ft_print_lst(lst);

	elem = ft_list_at(lst, 4);
	printf("4th elem: [%s]\n", (char *)elem->data);
	elem = ft_list_at(lst, 1);
	printf("1st elem: [%s]\n", (char *)elem->data);
	printf("15th elem: [%s]\n", ft_list_at(lst, 15) == NULL ? "(null)" : "error");
	printf("[INVALID] elem: [%s]\n", ft_list_at(lst, 0) == NULL ? "(null)" : "error");

	return (0);
}
