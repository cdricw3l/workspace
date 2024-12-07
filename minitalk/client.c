/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:10 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 15:17:06 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_msg(char *str, int pid)
{
	while (*str)
	{
		ft_send_bit_to_pid(*str, pid, 50);
		printf("\n");
		str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc == 1)
		return (1);
	pid = atoi(argv[1]);
	i = 2;
	printf("voici le pid %d\n", pid);
	while (argv[i])
		ft_send_msg(argv[i++], pid);
	return (0);
}
