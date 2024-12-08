/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:11:09 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 16:06:32 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_process_end(char **g_pid_string, int p, int *tm)
{
	usleep(150);
	kill(p, SIGUSR1);
	*tm = 0;
	printf("\nvoici le mwssage %s\n", *g_pid_string);
	free(*g_pid_string);
	*g_pid_string = NULL;

}

void	ft_process_str(char **g_pid_string, int *size_str, int j)
{
	char *tmp;
	
	if (*size_str == 0)
		*size_str = j;
	else
	{
		tmp = str_joint(*g_pid_string, j);
		free(*g_pid_string);
		*g_pid_string = tmp;
	}
}

void	ft_alloc_memory_str(char **g_pid_string, int p, int *tm)
{
	printf("voic tm %d\n", *tm);
	usleep(120);
	*g_pid_string = malloc(sizeof(char) * (*tm + 1));
	printf("confirmation de reception de la taille a traiter a pid %d\n", *tm + 1);
	*tm = -2;
	printf("confirmation de reception de la taille a traiter a pid %d\n", *tm + 1);
	*g_pid_string[0] = 0;
	kill(p, SIGUSR1);
	printf("En attente du message\n");

}

void	ft_handler(int n, siginfo_t *info, void *context)
{
	static char	*g_pid_string;
	static int	size_str = 0;
	static int	k = 7;
	static int	j = 0;
	int			p;

	(void)context;
	p = info->si_pid;
	if (n == 31)
		j = j | (((int)1 << k));
	if (--k < 0)
	{
		if (j == 0)
			ft_process_end(&g_pid_string, p, &size_str);
		else if (j == 0xff)
			ft_alloc_memory_str(&g_pid_string, p, &size_str);
		else
			ft_process_str(&g_pid_string,&size_str, j);
		k = 7;
		j = 0;
	}
}

int	main(void)
{
	int					i;
	struct sigaction	action;

	i = getpid();
	action.sa_sigaction = ft_handler;
	action.sa_flags = SA_SIGINFO;
	printf("voici le pid %d\n", i);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		sleep(1);
	return (0);
}
