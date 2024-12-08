/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:47:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 16:35:58 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_printbit(int n)
{
	int		bit;
	char	c;

	bit = 7;
	while (bit >= 0)
	{
		c = ((n >> bit) & 1) + '0';
		write(1, &c, 1);
		bit--;
	}
	printf("\n");
}

char	*str_joint(char *str, char c)
{
	int		len;
	int		i;
	char	*new_s;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	i = 0;
	new_s = malloc(sizeof(char) * (len + 2));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = str[i];
		i++;
	}
	new_s[i++] = c;
	new_s[i] = '\0';
	return (new_s);
}
