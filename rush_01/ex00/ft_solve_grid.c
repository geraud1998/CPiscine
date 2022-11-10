/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:08:09 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 23:04:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_backtracking_solver(int *grid, int n);

void	ft_print_grid(int *grid, int n);

/* Input imputation at the end of the grid */
void	ft_add_argv_to_grid(int *grid, int n, char **argv)
{
	int	start_index;
	int	count_num;
	int	i;

	i = 0;
	start_index = n * n;
	count_num = 0;
	while (argv[1][count_num] != '\0')
	{
		grid[start_index + count_num] = argv[1][count_num] - '0';
		count_num++;
	}
}

/* Grid initialization : null values and corresponding to the dimenssion N */
void	ft_create_grid(int *grid, int n, char **argv)
{
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			grid[row * n + col] = 0;
			col++;
		}
		row++;
	}
	ft_add_argv_to_grid(grid, n, argv);
}

/* Solving function : grid creation and backtracking launching */
void	ft_solve_grid(int *grid, int n, char **argv)
{
	ft_create_grid(grid, n, argv);
	ft_backtracking_solver(grid, n);
	if (grid[(n * n) - 1] == 0)
	{
		write(1, "Error\n", 6);
	}
	else
		ft_print_grid(grid, n);
}
