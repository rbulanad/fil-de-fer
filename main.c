/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:38:40 by rbulanad          #+#    #+#             */
/*   Updated: 2023/04/07 17:34:39 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixelput(t_img img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * img.line_length + x * (img.bpp / 8);
	dst = img.addr + offset;
	*(unsigned int*)dst = color;
}
	

void	line_x(t_img img, int x, int y, int len, int color)
{
	while (len != 0)
	{
		my_pixelput(img, x++, y, color);
		len--;
	}
}

void	line_y(t_img img, int x, int y, int len, int color)
{
	while (len != 0)
	{
		my_pixelput(img, x, y++, color);
		len--;
	}
}

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

int	absoluter(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	negativ(int num)
{
	if (num > 0)
		num *= -1;
	return (num);
}

void	bresenham(t_img img, t_coord *a, t_coord *b, int color)
{
	int	dx = b->x - a->x;
	int	dy = b->y - a->y;
	int	d = 2*dy-dx;
	int	right = 2 * dy;
	int	rightup = 2*(dy - dx);

	while (a->x != b->x)
	{
		if (d < 0)
		{
			my_pixelput(img, a->x, a->y, color);
			d += right;
		}
		if (d >= 0)
		{
			my_pixelput(img, a->x, a->y, color);
			a->y++;
			d += rightup;
		}
		a->x++;
	}
}

int	main(void)
{
	//create window
	t_data	data;
	t_img	img;
	data.mlx = mlx_init();
	window_maker(&data);
	img.img = mlx_new_image(data.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);

	//test grid
	int i = 50;
	int	color;
	while (i != 500)
	{
		color = 0x555555;
		if (i % 100 == 0)
			color = 0xBEBEBE;
		line_x(img, i, i, 500, color);
		line_y(img, i, 0, 500, color);
		i += 50;
	}

	//test bresenham
	t_coord	a;
	t_coord	b;

	a.x = 400;
	a.y = 300;
	b.x = 100;
	b.y = 100;
	line_x(img, (a.x - 10), a.y, 20, 0x00FD00); //point A
	line_y(img, a.x, (a.y - 10), 20, 0x00FD00);
	line_x(img, (b.x - 10), b.y, 20, 0x00FD00); //point B
	line_y(img, b.x, (b.y - 10), 20, 0x00FD00);
	bresenham(img, &a, &b, 0xFF0000);

	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0, 0);
	mlx_loop(data.mlx);

	return (0);
}
