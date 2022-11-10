/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:23:58 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/16 11:52:31 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_clean_argv(char **argv, int n);

void		ft_solve_grid(int *grid, int n, char **argv);

/* Input verification */
int	ft_count_valid_num(char **argv)
{
	char	*str;
	int		count_num;

	str = argv[1];
	count_num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (*(str + 1) >= '0' && *(str + 1) <= '9')
				return (0);
			count_num++;
		}
		else if (*str != ' ')
			return (0);
		else if ((*str == ' ') && (*(str - 1) == ' '))
			return (0);
		else if ((*(str + 1) == '\0') && (*(str) == ' '))
			return (0);
		str++;
	}
	return (count_num);
}

/* Input verification */
int	ft_check_argv(char **argv)
{
	char	*str;
	int		count_num;
	int		n;

	str = argv[1];
	if (!(str[0] >= '0' && str[0] <= '9') && (str[0] != '\0'))
		return (0);
	count_num = ft_count_valid_num(argv);
	if (count_num == 0 || count_num % 4 != 0)
		return (0);
	n = count_num / 4;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (!(*str >= '1' && *str <= n + '0'))
				return (0);
		}
		str++;
	}
	return (n);
}

void	ft_write_error(void)
{
	write(1, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	int	n;
	int	*grid;

	if (argc != 2)
	{
		ft_write_error();
		return (0);
	}
	n = ft_check_argv(argv);
	if (n == 1)
	{
		write(1, "1\n", 2);
		return (1);
	}
	if (n == 0)
	{
		ft_write_error();
		return (0);
	}
	ft_clean_argv(argv, n);
	grid = malloc(((n * n) + (4 * n)) * sizeof(*grid));
	ft_solve_grid(grid, n, argv);
	free(grid);
	return (0);
}
