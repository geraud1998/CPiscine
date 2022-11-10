/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:07:26 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:41:13 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H
# include "ft_list.h"

typedef struct s_data
{
	unsigned long	value;
	char			*name;
}				t_data;

t_list	*ft_create_dict(char *content);

t_data	*ft_dict_create_elem(unsigned long value, char *name);

void	ft_dict_clear(t_data *d);

int		ft_dict_cmp(t_data *d1, t_data *d2);


#endif