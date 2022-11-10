/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:22:08 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 12:40:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char w, char x, char y, char z);
void	solver(int i, int j);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 00;
	b = 01;
	solver(a, b);
}

void	print(char w, char x, char y, char z)
{
	if (w == '9' && x == '8' && y == '9' && z == '9')
	{
		write(1, &w, 1);
		write(1, &x, 1);
		write(1, " ", 1);
		write(1, &y, 1);
		write(1, &z, 1);
	}
	else
	{
		write(1, &w, 1);
		write(1, &x, 1);
		write(1, " ", 1);
		write(1, &y, 1);
		write(1, &z, 1);
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	solver(int i, int j)
{
	char	w;
	char	x;
	char	y;
	char	z;

	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{					
			w = i / 10 + '0';
			x = i % 10 + '0';
			y = j / 10 + '0';
			z = j % 10 + '0';
			print(w, x, y, z);
		j++;
		}
		i++;
	}
}
