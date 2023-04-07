/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:21:06 by rbulanad          #+#    #+#             */
/*   Updated: 2023/01/09 16:41:20 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signe;

	result = 0;
	i = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * signe);
}
/*
int main(void)
{
	char str[] = "12 3";
	char str2[] = "12 3";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str2));
}*/
