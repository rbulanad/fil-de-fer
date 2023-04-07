/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:51:44 by rbulanad          #+#    #+#             */
/*   Updated: 2023/04/04 11:05:12 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "get_next_line2/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> ///////////////////////////////////////////

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

int		kb_hooks(int key);
int		quit_win(void);
void	window_maker(t_data *data);
char	*freejoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		len(char *str);


#endif
