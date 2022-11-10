/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:37:56 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 11:44:52 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_to_allocate(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			count++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	return (count + (i * (size - 1)));
}

char	*ft_solver(int size, char **strs, char *sep, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
		{
			while (sep[j])
				str[k++] = sep[j++];
		}
		j = 0;
		i++;
	}
	str[k] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(*str) * 1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	str = malloc(sizeof(*str) * ft_size_to_allocate(size, strs, sep) + 1);
	if (!str)
		return (NULL);
	return (ft_solver(size, strs, sep, str));
}
