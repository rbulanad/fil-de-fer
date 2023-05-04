/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:51:44 by rbulanad          #+#    #+#             */
/*   Updated: 2023/05/04 19:36:22 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line_bonus.h"
# define HEIGHT 900
# define WIDTH 1000

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		color;
}				t_img;

typedef struct s_iso
{
	int	z;
	int	isox;
	int	isoy;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}				t_iso;

typedef struct s_coord
{
	int					width;
	int					height;
	struct s_iso		**tab;
}				t_coord;

typedef struct s_midpt
{
	int	x;
	int	y;
	int	z;
	int	hi_z;
}				t_midpt;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	int				fd;
	int				zoom;
	int				alti;
	int				yaxis;
	int				xaxis;
	struct s_img	img;
	struct s_coord	crd;
	struct s_iso	iso;
	struct s_midpt	md;
}				t_data;

char	**ft_split(char *s, char c);
int		len(char *s);
char	*joinfree(char *s1, char *s2);
int		ft_atoi(char *str);
int		abso(int num);
int		open_read(char *map);
int		file_read(t_data *data, char *map);
int		file_read2(t_data *data, char *map);
void	window_maker(t_data *data);
int		kb_hooks(int key, t_data *data);
int		mouse_hooks(int key, int x, int y, t_data *data);
int		quit_win(void);
void	image_maker(t_data *data);
void	iso_data(t_data *data);
void	my_pixelput(t_data *data, int x, int y, int color);
void	ft_draw(t_data *data);
int		color_check(t_data *data, int z);

#endif
