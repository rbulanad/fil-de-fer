/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:32:56 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:33 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_win(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img.img);
	image_maker(data);
	ft_draw(data);
}

int	mouse_hooks(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		data->alti++;
		clear_win(data);
	}
	if (key == 5)
	{
		data->alti--;
		if (data->alti < 0)
			data->alti = 0;
		clear_win(data);
	}
	return (0);
}

int	translation(int key, t_data *data)
{
	if (key == 126)
	{
		data->yaxis -= 4;
		clear_win(data);
	}
	if (key == 125)
	{
		data->yaxis += 4;
		clear_win(data);
	}
	if (key == 124)
	{
		data->xaxis += 4;
		clear_win(data);
	}
	if (key == 123)
	{
		data->xaxis -= 4;
		clear_win(data);
	}
	return (0);
}

int	kb_hooks(int key, t_data *data)
{
	translation(key, data);
	if (key == 116)
	{
		data->zoom++;
		clear_win(data);
	}
	if (key == 121)
	{
		data->zoom--;
		clear_win(data);
	}
	if (key == 53)
		exit(0);
	return (0);
}

int	quit_win(void)
{
	exit(0);
}
