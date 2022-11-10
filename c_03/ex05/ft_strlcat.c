/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:57:41 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/16 21:33:44 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	res;
	unsigned int	i;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	res = 0;
	i = 0;
	if (size == 0)
		res = len_src;
	else if (size < len_dst)
		res = len_src + size;
	else
		res = len_src + len_dst;
	if (size)
	{
		while ((len_dst + i) < (size - 1) && *(src + i) != 0)
		{
			*(dest + len_dst + i) = *(src + i);
			i++;
		}
		*(dest + len_dst + i) = 0;
	}
	return (res);
}
