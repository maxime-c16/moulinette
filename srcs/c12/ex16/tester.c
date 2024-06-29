/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:32:12 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 14:39:02 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

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

int	cmp_str(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_print_lst(lst);

	ft_list_push_back(&lst, "max");

	printf("Original list:\n");
	ft_print_lst(lst);

	printf("Applying ft_sorted_list_insert [cmp_str]:\n");
	ft_sorted_list_insert(&lst, "oce", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "toto", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "papa", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "mel", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "test", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "titi", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "titi", &cmp_str);
	ft_print_lst(lst);
	ft_sorted_list_insert(&lst, "abba", &cmp_str);
	ft_print_lst(lst);

	return (0);
}
