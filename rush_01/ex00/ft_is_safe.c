/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:19:45 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 23:04:48 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_double(int *grid, int n, int digit, int *row_col);

/* Count_check equals number of buildings you can see from 
the position */
int	ft_check_down(int *grid, int row, int col, int n)
{
	int	count_check;
	int	count_row;
	int	num_down;
	int	highest_building;

	if (row != n - 1)
		return (1);
	count_row = n - 1;
	count_check = 1;
	num_down = grid[(n * n) + n + col];
	highest_building = grid[(count_row * n) + col];
	while (count_row > 0)
	{
		if (highest_building < grid[(count_row - 1) * n + col])
		{
			highest_building = grid[(count_row - 1) * n + col];
			count_check++;
		}
		count_row--;
	}
	if ((count_check != num_down))
		return (0);
	return (1);
}

int	ft_check_up(int *grid, int col, int row, int n)
{
	int	count_check;
	int	count_row;
	int	num_up;
	int	highest_building;

	count_row = 0;
	count_check = 1;
	num_up = grid[(n * n) + col];
	highest_building = grid[(count_row * n) + col];
	while (count_row < n - 1)
	{
		if (highest_building < grid[(count_row + 1) + col])
		{
			highest_building = grid[(count_row + 1) + col];
			count_check++;
		}
		count_row++;
	}
	if ((count_check > num_up) || (row == n && count_check != num_up))
		return (0);
	return (1);
}

int	ft_check_right(int *grid, int row, int col, int n)
{
	int	count_check;
	int	count_col;
	int	num_right;
	int	highest_building;

	if (col != n - 1)
		return (1);
	count_col = n - 1;
	count_check = 1;
	num_right = grid[(n * n) + (3 * n) + row];
	highest_building = grid[(row * n) + count_col];
	while (count_col > 0)
	{
		if (highest_building < grid[(row * n) + count_col - 1])
		{
			highest_building = grid[(row * n) + count_col - 1];
			count_check++;
		}
		count_col--;
	}
	if (num_right != count_check)
		return (0);
	return (1);
}

int	ft_check_left(int *grid, int row, int col, int n)
{
	int	count_check;
	int	count_col;
	int	num_left;
	int	highest_building;

	count_col = 0;
	count_check = 1;
	num_left = grid[(n * n) + (2 * n) + row];
	highest_building = grid[(row * n) + count_col];
	while (count_col < n - 1)
	{
		if (highest_building < grid[(row * n) + count_col + 1])
		{
			highest_building = grid[(row * n) + count_col + 1];
			count_check++;
		}
		count_col++;
	}
	if ((count_check > num_left) || (col == n && count_check != num_left))
		return (0);
	return (1);
}

/* Verification : each value will have a place corresponding
to the input arguments (up, down, right, left) */
int	ft_is_safe(int *grid, int n, int digit, int *row_col)
{
	int	row;
	int	col;

	grid[(row_col[0] * n) + row_col[1]] = digit;
	row = row_col[0];
	col = row_col[1];
	if (ft_check_double(grid, n, digit, row_col) == 1)
	{
		if (ft_check_left(grid, row, col, n)
			&& ft_check_right(grid, row, col, n)
			&& ft_check_up(grid, col, row, n)
			&& ft_check_down(grid, row, col, n))
			return (1);
	}
	grid[(row_col[0] * n) + row_col[1]] = 0;
	return (0);
}
