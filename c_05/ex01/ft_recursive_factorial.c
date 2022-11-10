/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:07:08 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/18 14:46:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	if (nb < 0)
	{
		return (0);
	}
	else
	{
		if (nb >= 1)
		{
			fact = nb * ft_recursive_factorial(nb - 1);
		}
		else
		{
			return (1);
		}
	}
	return (fact);
}
