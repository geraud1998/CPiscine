/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:04:11 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 18:37:47 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

t_list	*ft_dict_error(t_list *l)
{
	ft_list_free(l, &ft_dict_clear);
	ft_putstr("Dict Error\n");
	return (NULL);
}

int		ft_is_valid_line(char *s, unsigned long *value, char **name)
{
	long	n;
	int		i;

	i = 0;
	while (ft_is_digit(s[i]))
		i++;
	if (!i || i > 18 || (n = ft_atol(s)) < 0)
		return (0);
	*value = n;
	s += i;
	while (ft_is_space(*s))
		s++;
	if (*s++ != ':')
		return (0);
	while (ft_is_space(*s))
		s++;
	*name = s;
	i = 0;
	while (s[i] && s[i] != '\n')
		if (!ft_is_printable(&s[i]))
			return (0);
		else if (ft_is_space(s[i++]))
			while (ft_is_space(s[i]))
				s++;	
	return (i && s[i] == '\n');
}

t_list	*ft_create_dict(char *content)
{
	t_list	*l;
	t_data	*e;
	t_data	t;

	l = NULL;
	while (*content)
	{
		if (*content == '\n')
			content++;
		else if (ft_is_valid_line(content, &t.value, &t.name)
				&& !ft_list_find(l, &t, ft_dict_cmp)
				&& (e = ft_dict_create_elem(t.value, t.name)))
		{
			ft_list_insert(&l, e, &ft_dict_cmp);
			while (*content != '\n')
				content++;
		}
		else
			return (ft_dict_error(l));
	}
	return (l);
}
