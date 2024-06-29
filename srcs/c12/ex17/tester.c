/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:37:39 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 18:56:53 by mcauchy          ###   ########.fr       */
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(void \
	*, void *))
{
	t_list	*prev;
	t_list	*new;
	t_list	*current;

	prev = NULL;
	new = ft_create_elem(data);
	if (!begin_list || !(*cmp) || !new)
		return ;
	current = *begin_list;
	while (current && (*cmp)(data, current->data) > 0)
	{
		prev = current;
		current = current->next;
	}
	if (!prev)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		prev->next = new;
		new->next = current;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst2;

	lst = NULL;
	lst2 = NULL;
	ft_print_lst(lst);
	ft_sorted_list_merge(&lst, lst2, &cmp_str);
	ft_sorted_list_merge(&lst, lst2, NULL);
	ft_sorted_list_merge(&lst, NULL, &cmp_str);
	ft_sorted_list_merge(NULL, lst2, &cmp_str);
	ft_sorted_list_merge(NULL, NULL, NULL);

	ft_sorted_list_insert(&lst, "maxime", &cmp_str);
	ft_sorted_list_insert(&lst, "tristan", &cmp_str);
	ft_sorted_list_insert(&lst, "melissa", &cmp_str);
	ft_sorted_list_insert(&lst, "oceane", &cmp_str);
	ft_sorted_list_insert(&lst, "laurent", &cmp_str);
	ft_sorted_list_insert(&lst, "alimata", &cmp_str);
	ft_sorted_list_insert(&lst, "valentine", &cmp_str);

	ft_sorted_list_insert(&lst, "cauchy", &cmp_str);
	ft_sorted_list_insert(&lst2, "aho", &cmp_str);
	ft_sorted_list_insert(&lst2, "samake", &cmp_str);
	ft_sorted_list_insert(&lst2, "cauchy", &cmp_str);
	ft_sorted_list_insert(&lst2, "aranda", &cmp_str);
	ft_sorted_list_insert(&lst2, "auzas", &cmp_str);

	printf("Original lists:\n");
	printf("n°1 ");
	ft_print_lst(lst);
	printf("n°2 ");
	ft_print_lst(lst2);

	printf("Applying ft_sorted_list_merge [cmp_str]:\n");
	ft_sorted_list_merge(&lst, lst2, &cmp_str);
	ft_print_lst(lst);
	return (0);
}
