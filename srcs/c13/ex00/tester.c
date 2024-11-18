/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:19:11 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/30 15:56:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

int	btree_depth(t_btree *node)
{
	int	depth_right;
	int	depth_left;

	depth_left = 0;
	depth_right = 0;
	if (!node)
		return (0);
	depth_left += btree_depth(node->left);
	depth_right += btree_depth(node->right);
	if (depth_right > depth_left)
		return (depth_right + 1);
	return (depth_left + 1);
}

void	print_tree(t_btree *node, int space, int level, int direction)
{
	int	i;

	i = level;
	if (!node)
	{
		for (int i = 0; i < space - 1; i++)
			printf(" ");
		printf("|---- (NULL)\n");
		return ;
	}
	space += level;
	print_tree(node->right, space, level, 1);
	printf("\n");
	while (i < space - 1)
	{
		printf(" ");
		i++;
	}
	if (direction == 1)
		printf(" /---- ");
	else if (direction == -1)
		printf(" \\---- ");
	else
		printf("      ");
	printf("%s\n", (char *)node->item);
	print_tree(node->left, space, level, -1);
}

void	btree_print(t_btree *node)
{
	int	spaces;
	int	depth;

	spaces= 0;
	depth = 0;
	printf("Binary tree:\n");
	if (node)
	{
		depth = btree_depth(node);
		spaces = depth * 5;
		print_tree(node, 0, spaces, 0);
	}
	else
		printf("(null)");
	printf("\n\n");
}

int	main(void)
{
	t_btree	*tree;

	tree = NULL;
	btree_print(tree);

	tree = btree_create_node("Head");
	tree->left = btree_create_node("Left");
	tree->right = btree_create_node("Right");
	tree->right->right = btree_create_node("RRight");
	tree->right->right->left = btree_create_node("RRLeft");
	btree_print(tree);

	return (0);
}
