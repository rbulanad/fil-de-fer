/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:46:51 by rbulanad          #+#    #+#             */
/*   Updated: 2023/04/07 14:46:35 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	kb_hooks(int key)
{
	if (key == 53)
		exit(0);
	else
		return (0);
}

int	quit_win(void)
{
	exit(0);
}

void	window_maker(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "caca");
	mlx_key_hook(data->mlx_win, kb_hooks, data);
	mlx_hook(data->mlx_win, 17, 0, quit_win, data);
}
