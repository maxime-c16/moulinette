/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:44 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/30 17:16:23 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

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

void	apply(void *item)
{
	printf("%s\n", (char *)item);
}

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_print(root);

	root = btree_create_node("Head");
	root->left = btree_create_node("Left");
	root->left->left = btree_create_node("LLeft");
	root->left->left->right = btree_create_node("LLRight");
	root->left->left->right->right = btree_create_node("LLRRight");
	root->right = btree_create_node("Right");
	root->right->right = btree_create_node("RRight");
	root->right->right->left = btree_create_node("RRLeft");
	btree_print(root);

	printf("Applying btree_apply_prefix [apply]:\n");
	btree_apply_prefix(root, &apply);

	return (0);
}
