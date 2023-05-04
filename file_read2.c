/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:54:53 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 18:50:53 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	size_malloc(t_data *data, int fd)
{
	char	*line;
	int		i;
	int		j;
	char	**split;

	j = 0;
	data->crd.width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		i = 0;
		while (split[i])
			i++;
		if (i > data->crd.width)
			data->crd.width = i;
		free(line);
		free_split(split);
		j++;
	}
	free(line);
	data->crd.height = j;
	close(fd);
}

int	malloc_tab(t_data *data)
{
	int	i;

	data->crd.tab = malloc(data->crd.height * sizeof(t_iso *));
	if (!data->crd.tab)
		return (1);
	i = 0;
	while (i < data->crd.height)
	{
		data->crd.tab[i] = malloc(data->crd.width * sizeof(t_iso));
		if (!data->crd.tab[i])
			return (1);
		i++;
	}
	return (0);
}

void	fill_tab(t_data *data, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			data->crd.tab[i][j].z = ft_atoi(split[j]);
			if (data->crd.tab[i][j].z > data->md.hi_z)
				data->md.hi_z = data->crd.tab[i][j].z;
		}
		free(line);
		free_split(split);
		i++;
	}
	free(line);
	close(fd);
}

int	file_read2(t_data *data, char *map)
{
	int	fd;

	fd = open_read(map);
	if (fd < 0)
		return (1);
	close(fd);
	size_malloc(data, open_read(map));
	if (malloc_tab(data) == 1)
		return (1);
	fill_tab(data, open_read(map));
	return (0);
}
