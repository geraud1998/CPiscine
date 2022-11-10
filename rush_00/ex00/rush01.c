/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:41:36 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/07 18:23:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	fl_lines(int c, int l, int x, int y)
{
	if ((c == 0 && l == 0) || (c == x - 1 && l == y - 1 && y != 1 && x != 1))
	{
		ft_putchar('/');
	}
	else if ((c == x - 1 && l == 0) || (c == 0 && l == y - 1))
	{
		ft_putchar(92);
	}
	else
	{
		ft_putchar('*');
	}
}

void	m_lines(int c, int x)
{
	if (c == 0 || c == x - 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	solver(int x, int y)
{
	int		c;
	int		l;

	c = 0;
	l = 0;
	while (l <= y - 1)
	{
		while (c <= x - 1)
		{
			if (l == 0 || l == y - 1)
			{
				fl_lines(c, l, x, y);
				c++;
			}
			else
			{
				m_lines(c, x);
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
