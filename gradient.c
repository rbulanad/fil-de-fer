/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:51:32 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 19:31:50 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_check(t_data *data, int z)
{
	float	highest;

	highest = (float)data->md.hi_z;
	if (data->alti == 0)
		return (0xFF0000);
	if (z <= highest / 4 && z > 0)
		return (0xFF3838);
	if (z <= highest / 3 && z > highest / 4)
		return (0xFF6D6D);
	if (z <= highest / 2 && z > highest / 3)
		return (0xFFADAD);
	if (z > highest / 2)
		return (0xFFFFFF);
	return (0xFF0000);
}
