/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:57:33 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/18 15:08:13 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	nb;

	nb = index;
	if (index < 0)
	{
		return (-1);
	}
	else
	{
		if (nb <= 1)
		{
			return (nb);
		}
		else
		{
			return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
		}
	}
}
