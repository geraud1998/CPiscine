/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:55:13 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 22:50:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putint(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
}

void	ft_print_grid(int *grid, int n)
{
	int	col;
	int	row;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			ft_putint(grid[row * n + col]);
			if (col != n - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
