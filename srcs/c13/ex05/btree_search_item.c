/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:56:42 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/30 18:21:02 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, \
	void *))
{
	void	*res;

	res = NULL;
	if (!root || !data_ref || !(*cmpf))
		return (NULL);
	if (root->left)
		res = btree_search_item(root->left, data_ref, (*cmpf));
	if (!res && !(*cmpf)(root->item, data_ref))
		res = root->item;
	if (!res && root->right)
		res = btree_search_item(root->right, data_ref, (*cmpf));
	return (res);
}
