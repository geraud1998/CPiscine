/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:09:52 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/10 18:56:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		count;
	int		save;

	count = 0;
	save = 0;
	while (count < (size / 2))
	{
		save = *(tab + size - 1 - count);
		*(tab + size - 1 - count) = *(tab + count);
		*(tab + count) = save;
		count++;
	}
}
