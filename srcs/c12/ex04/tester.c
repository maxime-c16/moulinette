/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:06:11 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 15:08:01 by mcauchy          ###   ########.fr       */
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

int	main(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = NULL;
	ft_print_lst(lst);
	ft_list_push_back(&lst, "First!");
	ft_print_lst(lst);
	ft_list_push_back(&lst, "Second");
	ft_print_lst(lst);
	ft_list_push_back(&lst, "Third");
	ft_print_lst(lst);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	return (0);
}
