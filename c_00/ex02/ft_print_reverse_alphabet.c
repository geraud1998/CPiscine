/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:39:46 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/07 11:10:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		count;
	char	c;

	count = 122;
	while (count > 96)
	{
		c = count;
		write(1, &c, 1);
		count--;
	}
}
