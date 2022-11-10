/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:10:14 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:32:40 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_create_elem(void *data)
{
	t_list *l;

	if (!(l = malloc(sizeof(t_list))))
		return (NULL);
	l->next = NULL;
	l->data = data;
	return (l);
}