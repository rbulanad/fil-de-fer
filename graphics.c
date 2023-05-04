/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:36:29 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 19:26:40 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
		dst = data->img.addr
		+ (y * data->img.line_length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	image_maker(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bpp, &data->img.line_length, &data->img.endian);
}

void	iso_data(t_data *data)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	while (y < data->crd.height)
	{
		x = 0;
		while (x < data->crd.width)
		{
			z = data->crd.tab[y][x].z;
			data->crd.tab[y][x].isox = (x - y)
				* (data->zoom) * cos(0.4) + data->xaxis + (WIDTH / 2);
			data->crd.tab[y][x].isoy = (x + y)
				* (data->zoom) * sin(0.6) + (data->yaxis + HEIGHT / 3)
				- z * data->alti;
			x++;
		}
		y++;
	}
}
