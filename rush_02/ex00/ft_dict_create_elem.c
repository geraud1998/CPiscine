/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:27:44 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 18:42:48 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

int		ft_dict_wordlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
		if (ft_is_space(s[i++]))
			while (ft_is_space(s[i]))
				s++;
	return (i);
}

t_data	*ft_dict_create_elem(unsigned long value, char *name)
{
	t_data	*d;
	int		i;

	i = ft_dict_wordlen(name);
	if (!i || !(d = malloc(sizeof(t_data))))
		return (NULL);
	d->value = value;
	d->name = malloc((i + 1) * sizeof(char));
	if (!d->name)
	{
		free(d);
		return (NULL);
	}
	i = 0;
	while (*name != '\n')
	{
		d->name[i++] = (ft_is_space(*name)) ? ' ' : *name++;
		while (ft_is_space(*name) && *name != '\n')
			name++;
	}
	d->name[i] = '\0';
	return (d);
}