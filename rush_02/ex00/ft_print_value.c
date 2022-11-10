/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:32:21 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/21 22:32:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"
#include "ft_dict.h"
#include "ft_list.h"

int	str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
	{
	}
	return (i-1);
}

void	print_hundred(t_list dict)
{
	char	*temp;

	temp = (char*)malloc(sizeof(char) * 4);
	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '\0';
	ft_putstr(dict[ft_atoi(temp)]);
	free(temp);
	return ;
}

void	print_thousand(t_list dict)
{
	char	*temp;

	temp = (char*)malloc(sizeof(char) * 5);
	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '\0';
	ft_putstr(dict[ft_atoi(temp)]);
	free(temp);
	return ;
}

void	print_million(t_list dict)
{
	char	*temp;

	temp = (char*)malloc(sizeof(char) * 8);
	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '0';
	temp[5] = '0';
	temp[6] = '0';
	temp[7] = '\0';
	ft_putstr(dict[ft_atoi(temp)]);
	free(temp);
	return ;
}

void	print_billion(t_list dict)
{
	char	*temp;

	temp = (char*)malloc(sizeof(char) * 11);
	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '0';
	temp[5] = '0';
	temp[6] = '0';
	temp[7] = '0';
	temp[8] = '0';
	temp[9] = '0';
	temp[10] = '\0';
	ft_putstr(dict[ft_atoi(temp)]);
	free(temp);
	return ;
}

void	what_qualificatif_to_write(int nb_of_digits_left_write, t_list dict)
{
	if (nb_of_digits_left_write > 0)
	{
		write(1, " ", 1);
		if (nb_of_digits_left_write == 3)
			print_thousand(dict);
		else if (nb_of_digits_left_write == 6)
			print_million(dict);
		else if (nb_of_digits_left_write == 9)
			print_billion(dict);
	}
	return ;
}

void	print_a_group_of_3_digits(char *str, int nb_digits_in_this_group, int i, t_list dict)
{
	char	*temp;

	if (nb_digits_in_this_group == 3)
	{
		if (str[i] != '0')
		{
			temp = (char*)malloc(sizeof(char) * 2);
			temp[0] = str[i];
			temp[1] = '\0';
			ft_putstr(dict[ft_atoi(temp)]);
			free(temp);
			write(1, " ", 1);
			print_hundred(dict);
			write(1, " ", 1);
		}
		i++;
		nb_digits_in_this_group --;
	}
	if (nb_digits_in_this_group == 2)
	{
		if (str[i] != '0')
		{
			temp = (char*)malloc(sizeof(char) * 3);
			temp[0] = str[i];
			if ((str[i] == '1') || (str[i + 1] == 0))
			{
				temp[1] = str[i + 1];
				i++;
				nb_digits_in_this_group--; 
			}
			else
				temp[1] = '0';
			temp[2] = '\0';
			ft_putstr(dict[ft_atoi(temp)]);
			free(temp);
			write(1, " ", 1);
		}
		i++;
		nb_digits_in_this_group--;
	}
	if (nb_digits_in_this_group == 1)
	{
		if (str[i] != '0')
		{
			temp = (char*)malloc(sizeof(char) * 2);
			temp[0] = str[i];
			temp[1] = '\0';
			ft_putstr(dict[ft_atoi(temp)]);
			free(temp);
		}
		i++;
		nb_digits_in_this_group--;
	}
	return ;
}

void    print_other_groups_of_3_digits(char *str, int nb_of_digits_left_write, int i, t_list dict)
{
	int		nb_digits_in_this_group;

	nb_digits_in_this_group = 3;
    if ((nb_digits_in_this_group > 0) && (str[i] != '\0'))
    {
		write(1, " ", 1);
		print_a_group_of_3_digits(str, nb_digits_in_this_group, i, dict);
		nb_of_digits_left_write -= nb_digits_in_this_group;
		if (!(str[i] && str[i] == '0' && str[i + 1] && str[i + 1] == '0' && str[i + 2]  && str[i + 2] == '0'))
			what_qualificatif_to_write(nb_of_digits_left_write, dict);
		print_other_groups_of_3_digits(str, nb_of_digits_left_write, (i + nb_digits_in_this_group), dict);
	}
	return ;
}

void	print_1st_groups_of_digits(char *str, int nb_digits_in_group_0, t_list dict)
{
	int		nb_of_digits_left_write;
	int		i;

	i = 0;
	nb_of_digits_left_write = str_len(str);
	if (str[i] == '\0')
	{
		return ;
	}
		else if (str[i] == '0' && str[i+1] == '\0')
	{
		ft_putstr(dict[0]);
	}
	else
	{
		print_a_group_of_3_digits(str, nb_digits_in_group_0, i, dict);
        nb_of_digits_left_write -= nb_digits_in_group_0;
		what_qualificatif_to_write(nb_of_digits_left_write, dict); 
		print_other_groups_of_3_digits(str, nb_of_digits_left_write, (i + nb_digits_in_group_0), dict);
	}
	return ;
}

void	ft_print_value(t_list dict, char *str)
{ 
	int		nb_digits;
	int		nb_digits_in_group_0;

	nb_digits_in_group_0 = 3;
	nb_digits = str_len(str);
	nb_digits_in_group_0 = nb_digits % 3;
	if (nb_digits_in_group_0 == 0)
		nb_digits_in_group_0 = 3;
	
	print_1st_groups_of_digits(str, nb_digits_in_group_0, dict);
	return ;
}
