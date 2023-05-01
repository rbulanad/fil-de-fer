/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:51:44 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/01 18:10:27 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line_bonus.h"
# include <stdio.h> ///////////////////////////////////////////
# define HEIGHT 800
# define WIDTH 800
# define ZOOM 20

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_iso
{
	int	x;
	int	y;
	int z;
	int	isox;
	int isoy;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	zoom;
}				t_iso;

typedef struct	s_coord
{
	int					numof_col;
	int					numof_row;
	struct s_iso		**tab;
}				t_coord;

typedef struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	struct s_img	img;
	struct s_coord	crd;
	struct s_iso	iso;
}				t_data;

char	**ft_split(char *s, char c);
int		len(char *s);
char	*joinfree(char *s1, char *s2);
int		ft_atoi(char *str);

#endif
