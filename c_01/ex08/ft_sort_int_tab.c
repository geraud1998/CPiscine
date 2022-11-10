/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:39:55 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/10 18:59:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		copy;

	copy = *a;
	*a = *b;
	*b = copy;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j != 0 && *(tab + j) < *(tab + j - 1))
		{
			ft_swap((tab + j), (tab + j - 1));
			j--;
		}
		i++;
	}
}
