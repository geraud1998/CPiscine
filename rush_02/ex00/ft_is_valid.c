/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:46:15 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/20 15:10:09 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_valid(char *value)
{
	int n;
	int i;

	if (!*value)
		return (0);
	n = 0;
	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
			return (0);
		else if (n || value[i] != '0')
			n++;
		i++;
	}
	return (n <= 12);
}