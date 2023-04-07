/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:14:43 by rbulanad          #+#    #+#             */
/*   Updated: 2022/12/22 16:30:57 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*temp[1024];
	char		*line;
	int			ret;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	buf = ft_calloc((BUFFER_SIZE + (ret = 1)), sizeof(char));
	while (ret > 0)
	{
		i = 0;
		while (temp[fd] && temp[fd][i] && temp[fd][i] != '\n')
			i++;
		if (temp[fd] && temp[fd][i++] == '\n')
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		temp[fd] = freejoin(temp[fd], buf);
	}
	line = ft_substr(temp[fd], 0, i);
	if (len(line) == 0)
		return (free(temp[fd]), temp[fd] = NULL, free(line), free(buf), NULL);
	temp[fd] = ft_substr(temp[fd], i, len(temp[fd]));
	return (free(buf), line);
}
/*
#include <stdio.h>
int main ()
{
	int		fd;
	int		fd2;
	int		i;
	char	*buf;
	i = 0;
	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	if (fd2 == -1)
	{
		printf("open error");
		return (1);
	}
	buf = get_next_line(fd);
	printf("%s\n", buf);
	buf = get_next_line(fd2);
	printf("%s\n", buf);
	buf = get_next_line(fd);
	printf("%s\n", buf);
	buf = get_next_line(fd2);
	printf("%s\n", buf);
}*/
