/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:39:12 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:46:01 by mcauchy          ###   ########.fr       */
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
	ft_list_sort(&lst, &cmp_str);
	ft_list_sort(NULL, &cmp_str);
	ft_list_sort(&lst, NULL);
	ft_list_sort(NULL, NULL);

	ft_list_push_back(&lst, "maxime");
	ft_list_push_back(&lst, "abc");
	ft_list_push_back(&lst, "Aa");
	ft_list_push_back(&lst, "melissa");
	ft_list_push_back(&lst, "oceane");
	ft_list_push_back(&lst, "tristan");
	ft_list_push_back(&lst, "papa");
	ft_list_push_back(&lst, "Lolo");
	ft_list_push_back(&lst, "MamAn");
	ft_list_push_back(&lst, "mAxime");

	printf("Original list:\n");
	ft_print_lst(lst);

	printf("Applying ft_list_sort [srtncmp] on list:\n");
	ft_list_sort(&lst, &cmp_str);
	ft_print_lst(lst);

}
