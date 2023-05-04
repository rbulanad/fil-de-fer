/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:46:47 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 19:31:55 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_midpt	md(int x, int y, int z)
{
	t_midpt	midpt;

	midpt.x = x;
	midpt.y = y;
	midpt.z = z;
	return (midpt);
}

void	midpoint(t_data *data, t_midpt start, t_midpt end)
{
	int	err;
	int	e2;

	data->iso.dx = abso(end.x - start.x);
	data->iso.dy = abso(end.y - start.y);
	data->iso.sx = ft_sx(start.x, end.x);
	data->iso.sy = ft_sy(start.y, end.y);
	err = data->iso.dx - data->iso.dy;
	while (1)
	{
		my_pixelput(data, start.x, start.y, color_check(data, start.z));
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 > -data->iso.dy)
		{
			err -= data->iso.dy;
			start.x += data->iso.sx;
		}
		if (e2 < data->iso.dx)
		{
			err += data->iso.dx;
			start.y += data->iso.sy;
		}
	}
}

void	ft_draw(t_data *d)
{
	int	y;
	int	x;

	iso_data(d);
	y = -1;
	while (++y < d->crd.height)
	{
		x = -1;
		while (++x < d->crd.width)
		{
			if (x < d->crd.width - 1)
				midpoint(d, md(d->crd.tab[y][x].isox, d->crd.tab[y][x].isoy,
						d->crd.tab[y][x].z),
					md(d->crd.tab[y][x + 1].isox, d->crd.tab[y][x + 1].isoy,
						d->crd.tab[y][x].z));
			if (y > 0)
				midpoint(d, md(d->crd.tab[y][x].isox, d->crd.tab[y][x].isoy,
						d->crd.tab[y][x].z),
					md(d->crd.tab[y - 1][x].isox, d->crd.tab[y - 1][x].isoy,
						d->crd.tab[y][x].z));
		}
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
}
