/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:11:09 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 15:11:26 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ft_handler(int n)
{
    static int i = 7;
    static int j = 0;
    
    if(n - 30 == 1)
        j = j | 1 << i;
    i--;
    if(i < 0)
    {
        write(1, &j, 1);
        i = 7;
        j = 0;
    }
    
}

int main() {

    int i = getpid();
    

    struct sigaction action;
    action.sa_handler = ft_handler;    
    action.sa_flags = SA_SIGINFO;
    action.sa_mask = 
    
    printf("voici le pid %d\n", i);
    
    sigaction(SIGUSR2 ,&action, NULL);
    sigaction(SIGUSR1 ,&action, NULL);
    
    while (1) {
        sleep(1); // Boucle infinie
    }

    return 0;
}