/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:14:41 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/24 12:20:25 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*temp;
	char		*line;
	int			ret;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp), temp = NULL, NULL);
	buf = ft_calloc((BUFFER_SIZE + (ret = 1)), sizeof(char));
	while (ret > 0)
	{
		i = 0;
		while (temp && temp[i] && temp[i] != '\n')
			i++;
		if (temp && temp[i++] == '\n')
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		temp = freejoin(temp, buf);
	}
	line = ft_substr(temp, 0, i);
	if (len(line) == 0)
		return (free(temp), temp = NULL, free(line), free(buf), NULL);
	temp = ft_substr(temp, i, len(temp));
	return (free(buf), line);
}
/*
#include <stdio.h>
int main ()
{
	int		fd;
	//int		fd2;
	//int		fd3;
	int		i;
	char	*buf;
	i = 0;
	fd = open("get_next_line.c", O_RDONLY);
	//fd2 = open("test2", O_RDONLY);
	//fd3 = open("test3", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	
	//if (fd2 == -1)
	//{
	//	printf("open error");
	//	return (1);
	//}
	//if (fd3 == -1)
	//{
	//	printf("open error");
	//	return (1);
	//}
	
	while (i < 113)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		i++;
	}
	
	//buf = get_next_line(fd);
	//printf("%s\n", buf);
	//buf = get_next_line(fd2);
	//printf("%s\n", buf);
	//buf = get_next_line(fd3);
	//printf("%s\n", buf);
	//buf = get_next_line(fd);
	//printf("%s\n", buf);
	//buf = get_next_line(fd2);
	//printf("%s\n", buf);
	//buf = get_next_line(fd3);
	//printf("%s\n", buf);
}*/
