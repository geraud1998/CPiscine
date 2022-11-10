/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:22:21 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/15 23:12:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{	
	int		i;
	int		j;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (*(str + i) != 0)
	{
		j = 0;
		while (*(str + i + j) == *(to_find + j) && *(str + i + j) != 0)
		{
			if (!*(to_find + j + 1))
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
