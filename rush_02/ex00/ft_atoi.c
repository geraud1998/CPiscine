/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:16:11 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/18 10:06:17 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		n;
	int		sign;
	int		number;

	n = 0;
	sign = 1;
	number = 0;
	while (*(str + n) == ' ' || (*(str + n) >= 9 && *(str + n) <= 13))
		n++;
	while (*(str + n) == '-' || *(str + n) == '+')
	{
		if (*(str + n) == '-')
			sign = -sign;
		n++;
	}
	if (*(str + n) >= '0' && *(str + n) <= '9')
	{
		while (*(str + n) >= '0' && *(str + n) <= '9')
		{
			number = number * 10 + *(str + n) - '0';
			n++;
		}
		return (number * sign);
	}
	return (0);
}
