/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:18:44 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/29 13:25:59 by mcauchy          ###   ########.fr       */
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
	t_list	*tmp;

	lst = NULL;
	tmp = NULL;
	ft_print_lst(lst);
	ft_list_merge(&lst, NULL);
	ft_list_merge(&lst, tmp);
	ft_list_merge(NULL, NULL);

	ft_list_push_back(&lst, "First");
	ft_list_push_back(&lst, "Second");
	ft_list_push_back(&lst, "Third");
	ft_list_push_back(&lst, "Fourth");
	ft_list_push_back(&lst, "Fifth");

	ft_list_push_back(&tmp, "Sixth");
	ft_list_push_back(&tmp, "Seventh");
	ft_list_push_back(&tmp, "Eighth");

	printf("Original list1:\n");
	ft_print_lst(lst);
	printf("Original list2:\n");
	ft_print_lst(tmp);

	printf("Applying ft_list_merge on list1 and list2:\n");
	ft_list_merge(&lst, tmp);
	ft_print_lst(lst);

	return (0);
}
