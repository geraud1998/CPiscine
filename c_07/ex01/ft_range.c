/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:52:39 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 21:46:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		n;
	int		*tab;

	n = 0;
	if (min >= max)
	{
		tab = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (0);
	while (n < (max - min))
	{
		tab[n] = min + n;
		n++;
	}
	return (tab);
}
