/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbegaga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:09:08 by fbegaga           #+#    #+#             */
/*   Updated: 2022/08/07 18:25:31 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	in_lines(int c, int l, int y, int x)
{
	if (c == 0 || c == x - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	out_lines(int c, int l, int y, int x)
{
	if (c == 0)
	{
		ft_putchar('A');
	}
	else if (c == x - 1)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	solver(int x, int y)
{
	int	c;
	int	l;

	c = 0;
	l = 0;
	while (l <= y - 1)
	{
		while (c <= x - 1)
		{
			if (l == 0 || l == y - 1)
			{
				out_lines(c, l, y, x);
				c++;
			}
			else
			{
				in_lines(c, l, y, x);
				c++;
			}
		}
		ft_putchar('\n');
		c = 0;
		l++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "ERROR : null or negative input variables", 40);
	}
	else
	{
		solver(x, y);
	}
}
