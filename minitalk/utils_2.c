/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:26:07 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 16:37:36 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_end_signal(int pid, int ms)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		kill(pid, SIGUSR1);
		usleep(ms);
		i++;
	}
}

void	send_separator_signal(int pid, int ms)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		kill(pid, SIGUSR2);
		usleep(ms);
		i++;
	}
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
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(ms);
		}
		bit--;
	}
}
