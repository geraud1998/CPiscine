/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:57:41 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 11:45:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char	*str)
{
	int		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	int		n;
	char	*new_src;
	int		len_src;

	n = 0;
	while (src[n])
		n++;
	len_src = n;
	new_src = malloc(sizeof(*new_src) * (len_src + 1));
	if (!new_src)
		return (NULL);
	n = 0;
	while (src[n])
	{
		new_src[n] = src[n];
		n++;
	}
	new_src[n] = '\0';
	return (new_src);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*dest;

	if (ac < 0)
		ac = 0;
	dest = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		dest[i].size = ft_strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = ft_strdup(av[i]);
		i++;
	}
	dest[i].str = 0;
	return (dest);
}
