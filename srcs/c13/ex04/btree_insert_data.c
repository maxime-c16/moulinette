/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:32:41 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/30 17:51:43 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (node)
	{
		node->left = NULL;
		node->right = NULL;
		node->item = item;
	}
	return (node);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, \
	void *))
{
	if (!root || !item || !(*cmpf))
		return ;
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, (*cmpf));
	else
		btree_insert_data(&(*root)->right, item, (*cmpf));

}
