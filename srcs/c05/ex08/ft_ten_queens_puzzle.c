/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:54:32 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/29 19:11:56 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tester.h"

void	print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d", board[i]);
		i++;
	}
	printf("\n");
}

int	check_rules(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col ||\
			board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		print_solution(board);
		(*count)++;
	}
	else
	{
		while (row < 10)
		{
			if (check_rules(board, row, col))
			{
				board[col] = row;
				solve(board, col + 1, count);
				board[col] = -1;
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	solve(board, 0, &count);
	return (count);
}
