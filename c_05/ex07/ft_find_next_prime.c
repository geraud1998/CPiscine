/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:41:42 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/21 11:26:54 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		i;

	i = 3;
	if (nb % 2 != 0)
	{
		while (i <= nb / i)
		{
			if (nb % i == 0)
				return (0);
			else
				i += 2;
		}
		return (1);
	}
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) != 1)
	{
		nb++;
		ft_is_prime(nb);
	}
	return (nb);
}
