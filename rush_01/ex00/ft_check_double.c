/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:01:41 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 22:49:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_col(int *grid, int n, int digit, int *row_col)
{
	int	count_row;
	int	row;
	int	col;

	row = row_col[0];
	col = row_col[1];
	count_row = 0;
	while (count_row < n)
	{
		if (count_row != row)
		{
			if (digit == grid[(count_row * n) + col])
				return (0);
		}
		count_row++;
	}
	return (1);
}

int	ft_check_row(int *grid, int n, int digit, int *row_col)
{
	int	count_col;
	int	row;
	int	col;

	row = row_col[0];
	col = row_col[1];
	count_col = 0;
	while (count_col < n)
	{
		if (count_col != col)
		{
			if (digit == grid[(row * n) + count_col])
				return (0);
		}
		count_col++;
	}
	return (1);
}

/* Check if a number is already in a column or in a row */
int	ft_check_double(int *grid, int n, int digit, int *row_col)
{
	if (ft_check_row(grid, n, digit, row_col) == 1)
	{
		if (ft_check_col(grid, n, digit, row_col) == 1)
			return (1);
	}
	return (0);
}
