/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:07:19 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:41:16 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_insert(t_list **begin_list, void *data, int (*cmp)());

void	ft_list_free(t_list *begin_list, void (*free_fct)());

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

t_list	*ft_list_create_elem(void *data);


#endif