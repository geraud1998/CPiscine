/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:18:36 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 14:21:25 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_free(t_list *begin_list, void (*free_fct)())
{
	if (!begin_list)
		return ;
	ft_list_free(begin_list->next, free_fct);
	if (free_fct)
		free_fct(begin_list->data);
	free(begin_list);
}