/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:03:16 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 11:44:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != 0)
	{
		n++;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	int		n;
	char	*new_src;
	int		len_src;	

	n = 0;
	len_src = ft_strlen(src);
	new_src = malloc(sizeof(*new_src) * len_src + 1);
	if (!new_src)
		return (NULL);
	while (*(src + n) != '\0')
	{
		*(new_src + n) = *(src + n);
		n++;
	}
	*(new_src + n) = '\0';
	return (new_src);
}
