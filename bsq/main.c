/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:52:51 by gt-serst          #+#    #+#             */
/*   Updated: 2022/08/23 14:06:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int	ft_write_in_file(char *content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '.')
		{
			content[i] = 'x';
		}	
		i++;
	}
	printf("%s", content);
	return (1);
}

int	ft_read_file(int fd_open)
{
	int		ret;
	char	buf[4096 + 1];
	char	*content;

	while ((ret = read(fd_open, buf, 4096)) > 0)
	{
		content = buf;
		content[ret] = 0;
	}
	printf("%s", content);
	ft_write_in_file(content);
	return (1);
}

int	ft_open_file(char	**argv)
{
	int	fd_open;
	
	fd_open = open(argv[1], O_RDONLY);
	if (fd_open < 0)
	{
		close(fd_open);
		return (0);	
	}
	ft_read_file(fd_open);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_open_file(argv);
	}
}
