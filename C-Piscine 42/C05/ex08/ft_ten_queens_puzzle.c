/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:38:02 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/18 13:58:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print(int chessboard[10][10])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			printf("%i ", chessboard[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	ft_clean_chessboard(int	chessboard[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			chessboard[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_queen(int chessboard[10][10], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		chessboard[x][i] = 1;
		chessboard[i][y] = 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if ((i - j) == (x - y) || (i + j) == (x + y))
				chessboard[i][j] = 1;
			j++;
		}
		i++;
	}
	chessboard[x][y] = 2; //delete then
}

void	ft_recursive(int chessboard[10][10])
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (chessboard[x][y] == 0)
				ft_queen(chessboard, x, y);
			x++;
		}
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	chessboard[10][10];

	ft_clean_chessboard(chessboard);
	ft_recursive(chessboard);
	ft_print(chessboard); 
	return (0);
}

int	main(void)
{
	ft_ten_queens_puzzle();
}
