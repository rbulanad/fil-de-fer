/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:16:07 by rbulanad          #+#    #+#             */
/*   Updated: 2022/12/22 16:16:17 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s2 || !s1)
		return (NULL);
	ret = ft_calloc((len(s1) + len(s2) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	return (ret);
}

char	*freejoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}

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
