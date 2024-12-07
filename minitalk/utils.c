/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:47:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 15:25:44 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_send_bit_to_pid(int n, int pid, int ms)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((n >> bit) & 1) == 0)
		{
			kill(pid, SIGUSR1);
			usleep(ms);
			printf("%d", SIGUSR1 - 30);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(ms);
			printf("%d", SIGUSR2 - 30);
		}
		bit--;
	}
}

int	ft_bit_to_int(int *arr_bit)
{
	int	num;
	int	i;
	int	b;

	b = 7;
	i = 0;
	num = 0;
	while (i <= 7)
	{
		if (arr_bit[i] == 1)
			num = num | 1 << b;
		i++;
		b--;
	}
	return (num);
}
