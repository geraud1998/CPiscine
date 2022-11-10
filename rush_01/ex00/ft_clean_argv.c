/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:54:42 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/14 22:49:37 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Replace argv after input cleaning */
void	ft_replace_argv(char **argv, char *cleaned_argv)
{
	int	count;

	count = 0;
	while (cleaned_argv[count] != '\0')
	{
		argv[1][count] = cleaned_argv[count];
		count++;
	}
	argv[1][count] = '\0';
	free(cleaned_argv);
}

/* Input transformation and imputation */
char	*ft_array_without_space(char *str, int n)
{
	char	*clean_str;
	int		count_clean_str;
	char	*ptr;

	clean_str = malloc(((4 * n)) * sizeof(*clean_str));
	count_clean_str = 0;
	ptr = clean_str;
	while (*str && (count_clean_str < 4 * n))
	{
		if (*str >= '1' && *str <= n + '0')
		{
			clean_str[count_clean_str] = *str;
			count_clean_str++;
		}
		str++;
	}
	clean_str[count_clean_str] = '\0';
	return (ptr);
}

void	ft_clean_argv(char **argv, int n)
{
	char	*cleaned_argv;

	cleaned_argv = ft_array_without_space(argv[1], n);
	ft_replace_argv(argv, cleaned_argv);
}
