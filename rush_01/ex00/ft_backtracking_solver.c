/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_solver.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:20:47 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 23:01:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_safe(int *grid, int n, int digit, int *row_col);

/* Find empty space in grid */
int	ft_empty_spc(int *grid, int n, int *row_col)
{
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (grid[(row * n) + col] == 0)
			{
				row_col[0] = row;
				row_col[1] = col;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

/* First, find empty space, if empty space return 0 it means that
every cases have a right value */
int	ft_backtracking_solver(int *grid, int n)
{
	int	digit;
	int	row_col[2];
	int	i;

	i = 0;
	if (ft_empty_spc(grid, n, row_col) == 0)
		return (1);
	digit = 1;
	while (digit <= n)
	{
		if (ft_is_safe(grid, n, digit, row_col) == 1)
		{
			grid[(row_col[0] * n) + row_col[1]] = digit;
			if (ft_backtracking_solver(grid, n))
				return (1);
			grid[(row_col[0] * n) + row_col[1]] = 0;
		}
		digit++;
	}
	return (0);
}
