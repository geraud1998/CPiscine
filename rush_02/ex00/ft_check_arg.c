/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:45:53 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:59:12 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_check_arg(int argc, char **argv, char **path, char **value)
{
	if (argc < 2 || argc > 3)
	{
		*path = NULL;
		*value = NULL;
	}
	if (argc == 2)
	{
		*path = "numbers.dict.txt";
		*value = argv[1];
	}
	else
	{
		*path = argv[1];
		*value = argv[2];
	}
}