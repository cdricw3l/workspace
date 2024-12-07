/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:11:09 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 09:39:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ft_printbit(int n)
{
    int bit;

    bit = 7;
    while(bit >= 0)
    {
        char c = ((n >> bit) & 1) + '0';
        write(1, &c, 1);
        bit--;
    }
    printf("\n");
}

void ft_handler(int n)
{
    static int x = 0;
    static int i = 7;
    x = x | n << i;
    ft_printbit(x);
    if (i == 1)
        i = 7;
    else
        i--;
    //printf("%d\n", x);  
  
    
}

int main() {

    int i = getpid();
    

    struct sigaction action;
    action.sa_handler = ft_handler;    
    action.sa_flags = SA_SIGINFO;
    action.sa_mask = 
   
    sigaction(SIGUSR2 ,&action, NULL);
    sigaction(SIGUSR1 ,&action, NULL);
    
    printf("%d\n",i);
    while (1) {
        sleep(1); // Boucle infinie
    }

    return 0;
}