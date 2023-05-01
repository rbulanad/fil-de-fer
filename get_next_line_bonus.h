/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:36 by rbulanad          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:08 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "fdf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

char	*get_next_line(int fd);
char	*ft_substr(char *s1, unsigned int start, int end);
int		len(char *str);
void	ft_strncpy(char *dst, char *src, int size);
void	*ft_calloc(int count, int size);
void	ft_bzero(void *str, int n);

#endif
