/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:12:46 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/16 18:15:06 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size)
	{
		while ((*(src + i) != '\0') && (i < (size - 1)))
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = 0;
	}
	return (len_src);
}
