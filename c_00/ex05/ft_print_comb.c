/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:50:02 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 12:40:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char x, char y, char z);
void	solver(int i, int j, int k);

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 48;
	b = 49;
	c = 50;
	solver(a, b, c);
}

void	print(char x, char y, char z)
{
	if (x == 55 && y == 56 && z == 57)
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, &z, 1);
	}
	else
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, &z, 1);
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	solver(int i, int j, int k)
{
	while (i < 56)
	{
		while (j < 57)
		{
			while (k < 58)
			{
				if (i < j && j < k)
				{
					print(i, j, k);
				}
				k++;
			}
			j++;
			if (k == 58)
			{
				k = 49;
			}
		}
			i++;
		if (j == 57)
		{
			j = 50;
		}
	}
}
