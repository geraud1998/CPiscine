/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:50:18 by lowathar          #+#    #+#             */
/*   Updated: 2022/08/21 16:01:00 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

char	*ft_check_len(int len, char *content)
{
	if(len != 0)
	{
		free(content);
		return (NULL);
	}
	else
	return (content);
}


char	*ft_file_read(int fd)
{
	char	buf[4096];
	char	*content;
	char	*tmp;
	int		len;
	int		size;

	content = malloc(sizeof(char));
	if (!content)
		return (NULL);
	*content = '\0';
	size = 0;
	while ((len = read(fd, buf, 4096)) > 0)
	{
		tmp = malloc((size + len + 1) * sizeof(char));
		if (!tmp)
			break;
		tmp = ft_strncpy(tmp, content, size);
		free(content);
		ft_strncpy(tmp + size, buf, len);
		content = tmp;
		size += len;
		content[size] = '\0';
	}
	return(ft_check_len(len, content));
}

char	*ft_file_open(char *path)
{
	char			*content;
	int				fd;

	fd = open(path, O_RDONLY);	
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd);
	if (fd != STDIN_FILENO)
		close(fd);
	return (content);
}