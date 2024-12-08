/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:10 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 14:11:52 by cw3l             ###   ########.fr       */
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
	int len;
	
	len = ft_strlen(str);
	ft_send_bit_to_pid(len, pid, 100);
	send_separator_signal(pid,100);
	printf("le client rentre en pause \n");
	pause();
	usleep(210);
	printf("Après pause\n");
	while (*str)
	{
		ft_send_bit_to_pid(*str, pid, 100);
		str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t	serveur_pid;
	int		i;
	struct sigaction	action;

	int					client_pid;

	client_pid = getpid();
	action.sa_handler= ft_handler_reception;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);

	if (argc == 1)
		return (1);
	serveur_pid = atoi(argv[1]);
	i = 2;
	printf("PID client: %d\n", client_pid);
	printf("PID serveur: %d\n", serveur_pid);
	while (argv[i])
	{
		ft_send_msg(argv[i++], serveur_pid);
		printf("envoi du message de fin\n");
		send_end_signal(serveur_pid, 100);
		pause();
		printf("Le message a bien été envoye au serveur %d\n", serveur_pid);
	}
	
	return (0);
}
