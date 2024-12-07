/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:11:09 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 21:15:44 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// void add_value_in_arr(int *arr[INT_MAX], int n)
// {
	
// }
int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*str)
		i++;
	return(i);
}


void	ft_handler(int n, siginfo_t* info, void* context)
{
	int pid = info->si_pid;
	static int k = 7;
	static int j = 0;


	(void)context;
	(void)info;
	if(n == 31)
		j = j | ((1 << k) & 1); 
	k--;
	if(k < 0)
	{
		printf("voici j %d\n",j);
		char c = j + '0';
		write(1, &c,1);
		k--;
	}
	printf("%d",j);
	//ft_strjoin(j[pid], c);
	kill(pid,n);
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

int	main(void)
{
	int					i;
	struct sigaction	action;

	i = getpid();
	// j = malloc(sizeof(int) * INT_MAX);
	// if(!j)
	// 	return (1);
	
	action.sa_sigaction = ft_handler;
	action.sa_flags = SA_SIGINFO;
	printf("voici le pid %d\n", i);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);

	while (1)
		sleep(1);
	return (0);
}
