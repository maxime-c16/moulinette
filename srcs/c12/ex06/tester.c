/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:28:41 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 15:46:36 by mcauchy          ###   ########.fr       */
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

void	free_data(void *data)
{
	free(data);
}

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_print_lst(lst);

	ft_list_push_back(&lst, strdup("First node!"));
	ft_list_push_back(&lst, strdup("Second"));
	ft_list_push_back(&lst, strdup("Third"));
	ft_print_lst(lst);

	ft_list_clear(lst, &free_data);
	lst = NULL;
	printf("after deletion\n");
	ft_print_lst(lst);
	if (!lst)
		printf("deletion complete\n");
	else
		printf("Unable to delete list\n");
	return (0);
}
