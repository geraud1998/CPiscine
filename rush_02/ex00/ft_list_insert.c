/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:06:10 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:30:08 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_dict.h"
#include "ft_list.h"

void	ft_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *e;

	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		if (!(e = ft_list_create_elem(data)))
			return ;
		e->next = *begin_list;
		*begin_list = e;
	}
	else
		ft_list_insert(&(*begin_list)->next, data, cmp);
}