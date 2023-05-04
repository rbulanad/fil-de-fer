/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:40:22 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 16:48:22 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abso(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	open_read(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

void	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, kb_hooks, data);
	mlx_mouse_hook(data->mlx_win, mouse_hooks, data);
	mlx_hook(data->mlx_win, 17, 0, quit_win, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.zoom = 20;
	data.alti = 1;
	data.yaxis = 1;
	data.xaxis = 1;
	data.img.color = 0xFF0000;
	if (argc < 2)
		return (write(1, "ERR NO MAP\n", 11), 0);
	data.mlx = mlx_init();
	if (data.fd == -1)
		return (write(1, "ERR OPEN\n", 9), 1);
	if (file_read2(&data, argv[1]) == 1)
		return (write (1, "ERR WRONG MAP\n", 14), 1);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "caca");
	image_maker(&data);
	ft_draw(&data);
	hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
