/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:10 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 14:20:43 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_msg(char *str, int pid)
{
    while (*str)
    {
        ft_send_bit_to_pid(*str, pid, 20);
        printf("\n");
        str++;
    }
     printf("\n");
    
}

int ft_bit_to_int(int *arr_bit, int num)
{
    int i = 0;
    int b = 7;
    while (i <= 7)
    {
        if(arr_bit[i] == 1)
            num = num | 1 << b;
        i++;
        b--;
    }
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
        ft_send_msg(argv[i++], pid);
    
    int x = 0;
    int arr[] =  {0,0,0,0,1,0,1,0};

    
    
    printf("voici x %d\n",x);
   // x = x|1 << 2;
    ft_printbit(x);
 
    return(0);
}   