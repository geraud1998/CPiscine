/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:27:36 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 17:51:04 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"
#include "ft_list.h"

void	ft_print_value(t_list dict, char *str);

int	main(int argc, char **argv)
{
	char	*value;
	char	*path;
	char	*content;
	t_list	*dict;

	ft_check_arg(argc, argv, &path, &value);
	if (!ft_is_valid(value))
		ft_putstr("Error\n");
	else if ((content = ft_file_open(path)))
	{
		dict = ft_create_dict(content);
		free(content);
		if (dict)
		{
			ft_print_value(dict, value);
			ft_list_free(dict, &ft_dict_clear);
		}
	}
	else
		ft_putstr("Dict Error\n");
	return (0);


}