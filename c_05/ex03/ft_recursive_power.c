/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:32:07 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/18 14:50:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	pwr;

	if (power < 0)
	{
		return (0);
	}
	else
	{
		if (power >= 1)
		{
			pwr = nb * ft_recursive_power(nb, power - 1);
		}
		else
		{
			return (1);
		}
	}
	return (pwr);
}
