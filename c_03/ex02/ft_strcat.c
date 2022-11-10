/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:43:34 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/13 21:16:41 by gt-serst         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int		len_dst;
	int		i;

	len_dst = ft_strlen(dest);
	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + len_dst + i) = *(src + i);
		i++;
	}
	*(dest + len_dst + i) = 0;
	return (dest);
}
