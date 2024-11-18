/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:22:57 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/30 18:28:39 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	max_depth(t_btree *node)
{
	int	max_right;
	int	max_left;

	max_right = 0;
	max_left = 0;
	if (!node)
		return 0;
	max_left = max_depth(node->left);
	max_right = max_depth(node->right);
	if (max_left > max_right)
		return (max_left + 1);
	else
		return (max_right + 1);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (max_depth(root) - 1);
}
