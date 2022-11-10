/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:07:23 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 15:41:14 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_check_arg(int argc, char **argv, char **path, char **value);

int		ft_is_valid(char *value);

char	*ft_file_open(char *path);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_putstr(char *str);

int		ft_is_printable(char *str);

int		ft_is_digit(char c);

int		ft_is_space(char c);

long	ft_atol(char *str);

int		ft_strlen(char *str);

int	    ft_atoi(char *str);

#endif