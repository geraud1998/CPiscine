/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:07:21 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/25 22:42:50 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_strs(char *str, char *charset)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_charset(str[i], charset) == 1)
			str++;
		if (str[i] != '\0')
			j++;
		while (str[i] != '\0' && ft_charset(str[i], charset) == 0)
			i++;
	}
	return (j);
}

int	ft_word_length(char *str, char *charset)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_charset(str[i], charset) == 0)
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = ft_word_length(str, charset);
	dest = malloc(sizeof(char) * (j + 1));
	while (i < j)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		j;

	j = 0;
	dest = malloc(sizeof(char *) * (ft_count_strs(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && ft_charset(*str, charset) == 1)
			str++;
		if (*str != '\0')
		{
			dest[j] = ft_word(str, charset);
			j++;
		}
		while (*str != '\0' && ft_charset(*str, charset) == 0)
			str++;
	}
	dest[j] = 0;
	return (dest);
}
