/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:10 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 11:02:36 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler_reception(int n)
{
	char *c;
	
	if(n == 30)
	{
		c = "message bien recu\n";
		write(1, c, 19);
	}
	else
	{
		c = "erreur\n";
		write(1, c, 8);
	}
}

static void	ft_send_msg(char *str, int pid)
{
	
	while (*str)
	{
		ft_send_bit_to_pid(*str, pid, 100);
		printf("\n");
		str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	struct sigaction	action;

	action.sa_handler= ft_handler_reception;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);

	if (argc == 1)
		return (1);
	pid = atoi(argv[1]);
	i = 2;
	printf("voici le pid %d\n", pid);
	while (argv[i])
	{
		ft_send_msg(argv[i++], pid);
		send_end_signal(pid, 100);
	}
	
	return (0);
}
