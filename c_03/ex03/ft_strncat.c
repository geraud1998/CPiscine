/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:48:49 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/15 23:10:54 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src)
{
	int		n;

	n = 0;
	while (*(src + n) != 0)
	{
		n++;
	}
	return (n);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	while (*(src + i) != 0 && i < nb)
	{
		*(dest + len_dst + i) = *(src + i);
		i++;
	}
	*(dest + len_dst + i) = 0;
	return (dest);
}
