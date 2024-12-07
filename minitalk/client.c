/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:10 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 08:12:25 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_bit(int n, int pid)
{
    int bit = 7;

    while (bit >= 0)
    {
        if(((n >> bit)  & 1) == 0)
        {

            kill(pid, SIGUSR1);
            usleep(10);
            printf("%d",SIGUSR1 - 30);
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(10);
            printf("%d",SIGUSR2 - 30);
        }
        bit--;
    }
    
}

void ft_convert_to_binairy(char *str, int pid)
{
    while (*str)
    {
        ft_send_bit(*str, pid);
        printf("\n");
        str++;
    }
     printf("\n");
    
}

int main(int argc, char **argv)
{
    pid_t pid;

    if(argc == 1)
        return 1 ;
    pid = atoi(argv[1]);
    printf("voici le pid %d\n",pid);
    int i = 2;
    while (argv[i])
    {
        ft_convert_to_binairy(argv[i], pid);
        i++;
    }
    
}