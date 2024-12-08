/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:11:09 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 12:30:32 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int **pid;

void	ft_handler(int n, siginfo_t* info, void* context)
{
	int p = info->si_pid;
	static int k = 7;
	static int j = 0;

	if(pid[p] == NULL)
	{
		ft_bzero(pid[p]);
	}
	(void)context;
	if(n == 31)
		j = j | (((int)1 << k)); 
	k--;
	if(k < 0)
	{
		pid[p] = add_nb(pid[p], j);
		printf("%c", (int)j);
		printf("\n");
		ft_printbit(j);
		if(j == 0)
		{
			printf("\nfin du message\n");
			exit(0);
		}
		k = 7;
		j = 0;
	}
	//ft_strjoin(j[pid], c);
	//kill(pid,n);
	fflush(stdout);
	
}

void set_zero(int arr[], int len)
{
	int i;
	write(1, "\n", 1);

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
}

void init_arr(int **arr, int max)
{
	int i;

	i = 0;
	while(i < max)
		arr[i++] = NULL;
}

int	main(void)
{
	int					i;
	struct sigaction	action;

	i = getpid();
	pid = malloc(sizeof(char *) * (PID_MAX));
	if(!pid)
		return (1);
	init_arr(pid,PID_MAX);
	action.sa_sigaction = ft_handler;
	action.sa_flags = SA_SIGINFO;
	printf("voici le pid %d\n", i);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);

	while (1)
		sleep(1);
	return (0);
}
