/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:47:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 13:50:08 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void ft_send_bit_to_pid(int n, int pid, int ms)
{
    int bit = 7;

    while (bit >= 0)
    {
        if(((n >> bit)  & 1) == 0)
        {

            kill(pid, SIGUSR1);
            usleep(ms);
            printf("%d",SIGUSR1 - 30);
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(ms);
            printf("%d",SIGUSR2 - 30);
        }
        bit--;
    }
    
}