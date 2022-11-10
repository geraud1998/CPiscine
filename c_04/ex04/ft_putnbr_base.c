/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:19 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 11:43:29 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*(str + n) != 0)
	{
		n++;
	}
	return (n);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base[i])
		return (0);
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_convert_base(long nbr, char *base, int len_base)
{
	long		remainder;

	if (nbr != 0)
	{
		ft_convert_base(nbr / len_base, base, len_base);
		remainder = nbr % len_base;
		ft_putchar(base[remainder]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	long	l;

	l = nbr;
	len_base = ft_strlen(base);
	if (ft_check_base(base))
	{
		if (l == 0)
		{
			ft_putchar(base[0]);
		}
		else if (l < 0)
		{
			ft_putchar('-');
			l = -l;
			ft_convert_base(l, base, len_base);
		}
		else
			ft_convert_base(l, base, len_base);
	}
}
