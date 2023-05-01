/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:40:22 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/01 18:23:07 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/////////////////////// WINDOW /////////////////////////////
int	kb_hooks(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	quit_win(void)
{
	exit(0);
}

int	zoom(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	data->iso.zoom += 1;
	return (0);
}

void	window_maker(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "caca");
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->mlx_win, kb_hooks, data);
	mlx_hook(data->mlx_win, 17, 0, quit_win, data);
	mlx_hook(data->mlx_win, 126, 0, zoom, data);
}
/////////////////////// FILE READ //////////////////////////

void	counter_formalloc(t_data *data, char **filetab)
{
	int	i;
	int	j;
	int	numof_col;

	i = 0;
	j = 0;
	while (filetab[i])
	{
		j = 0;
		numof_col = 1;
		while (filetab[i][j])
		{
			if (filetab[i][j] != ' ' && filetab[i][j] != '\n' && filetab[i][j + 1] == ' ')
				numof_col++;
			j++;
		}
		data->crd.numof_col = numof_col;
		i++;
	}
	data->crd.numof_row = i;
	data->crd.tab = malloc(i * sizeof(t_iso*));
	j = 0;
	while (j < i)
		data->crd.tab[j++] = malloc(numof_col * sizeof(t_iso));
}

void	file_to_tab(t_data *data, char *file)
{
	char	**filetab;
	char	**tmptab;
	int		i;
	int		j;

	filetab = ft_split(file, '\n');
	counter_formalloc(data, filetab);
	i = 0;
	while (filetab[i])
	{
		j = 0;
		tmptab = ft_split(filetab[i], ' ');
		while (j < data->crd.numof_col)
		{
			data->crd.tab[i][j].z = ft_atoi(tmptab[j]);
			j++;
		}
		free(tmptab);
		i++;
	}
}

int	file_read(t_data *data, char *map)
{
	char	*file;
	char	*tmpfile;
	int		fd;

	file = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		tmpfile = get_next_line(fd);
		if (tmpfile == NULL)
			break;
		file = joinfree(file, tmpfile);
		free(tmpfile);
	}
	file_to_tab(data, file);
	return (0);
}

//////////////////////// GRAPHIQUE //////////////////////////

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void	horizontal(t_data *data, int x1, int x2, int y)
{
	int	temp;

	if (x2 < x1)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
	while (x1 < x2)
		my_pixelput(data, x1++, y, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

void	vertical(t_data *data, int y1, int y2, int x)
{	
	int	temp;

	if (y2 < y1)
		{
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
	while (y1 < y2)
		my_pixelput(data, x, y1++, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

void	image_maker(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_length, &data->img.endian);
}

void	iso_data(t_data *data)
{
	int	x;
	int	y;
	int	z;

	data->iso.zoom = 1;
	y = 0;
	while (y < data->crd.numof_row)
	{
		x = 0;
		while (x < data->crd.numof_col)
		{
			z = data->crd.tab[y][x].z;
			data->crd.tab[y][x].isox = (x - y) * (data->iso.zoom + ZOOM) * cos(0.5) + WIDTH/2;
			data->crd.tab[y][x].isoy = (x + y) * (data->iso.zoom + ZOOM) * sin(0.6) + HEIGHT/3 - z;
			//20 is the zoom amount; inside cos 0.139, sin 0.523599is X axis rotation, 50 is up down right left movement; add "- z" to isoy for relief
			x++;
		}
		y++;
	}
}

/*
void	bresenham(t_data *data, int x1, int y1, int x2, int	y2)
{
	int		dx;
	int		dy;
	float	y;
	float	incr;

	y = (float) y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0)
		vertical(data, y1, y2, x1);
	else
	{
		incr = (float) dy / (float) dx;
		while (x1 < x2)
		{
			my_pixelput(data, x1, y, 0xFF0000);
			y += incr;
			x1++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}*/

int	abso(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	ft_sx(int x1, int x2)
{
	int	sx;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	return (sx);
}

int	ft_sy(int y1, int y2)
{
	int	sy;

	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	return (sy);
}

void	midpoint(t_data *data, int x1, int y1, int x2, int	y2)
{
	int	err;
	int	e2;

	data->iso.dx = abso(x2 - x1);
	data->iso.dy = abso(y2 - y1);
	data->iso.sx = ft_sx(x1, x2);
	data->iso.sy = ft_sy(y1, y2);
	err = data->iso.dx - data->iso.dy;
	while (x1 != x2 && y1 != y2)
	{
		my_pixelput(data, x1, y1, 0xFF0000);
		e2 = 2 * err;
		if (e2 > -data->iso.dy)
		{
			err -= data->iso.dy;
			x1 += data->iso.sx;
		}
		if (e2 < data->iso.dx)
		{
			err += data->iso.dx;
			y1 += data->iso.sy;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

void	ft_draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->crd.numof_row)
	{
		x = 0;
		while (x < data->crd.numof_col)
		{
			if (x < data->crd.numof_col - 1)
			{
				midpoint(data, data->crd.tab[y][x].isox, data->crd.tab[y][x].isoy, data->crd.tab[y][x + 1].isox, data->crd.tab[y][x + 1].isoy);
			}
			if (y > 0)
			{
				midpoint(data, data->crd.tab[y][x].isox, data->crd.tab[y][x].isoy, data->crd.tab[y - 1][x].isox, data->crd.tab[y - 1][x].isoy);
			}
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return(printf("no map\n"), 0);
	data.mlx = mlx_init();
	if (file_read(&data, argv[1]) == -1)
		return (printf("wrong file"), 1);/////////////
	window_maker(&data);
	image_maker(&data);
	iso_data(&data);
	ft_draw(&data);
	hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
