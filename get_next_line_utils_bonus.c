/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:16:07 by rbulanad          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:47 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s1, unsigned int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	ret = ft_calloc((end - start + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ft_strncpy(ret, &s1[start], end - start);
	if (start > 0)
		free(s1);
	return (ret);
}

void	ft_strncpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (i < (size) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_bzero(void *str, int n)
{
	unsigned char	*tmp;
	int				i;

	if (n == 0)
		return ;
	tmp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
