/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:25:50 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 11:44:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		n;

	n = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(**range) * (max - min));
	if (!*range)
		return (-1);
	while (n < (max - min))
	{
		range[0][n] = min + n;
		n++;
	}
	return (max - min);
}
