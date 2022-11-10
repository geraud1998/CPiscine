/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:28:14 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/18 20:59:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int			n;

	n = 0;
	while (str[n] != '\0')
	{
		write(1, &str[n], 1);
		n++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		n;

	n = 0;
	while (*(s1 + n) != '\0' || *(s2 + n) != '\0')
	{
		if (*(s1 + n) == *(s2 + n))
			n++;
		else
		{
			return (*(s1 + n) - *(s2 + n));
		}
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*copy;

	copy = *a;
	*a = *b;
	*b = copy;
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 2;
	while (argc > 2)
	{
		j = i;
		while (j != 1 && ft_strcmp(argv[j], argv[j - 1]) < 0)
		{
			ft_swap(&argv[j], &argv[j - 1]);
			j--;
		}
		i++;
		argc--;
	}
	if (argc == 2)
	{
		while (argc <= i)
		{
			ft_putstr(argv[argc - 1]);
			ft_putchar('\n');
			argc++;
		}
	}
	return (0);
}
