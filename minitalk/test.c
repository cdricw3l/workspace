/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:49:59 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/07 21:05:22 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_add_num(int *j[INT_MAX], int pid, int n)
{
    int *arr = j[pid];
    int i = 0;

    if(!arr[0])
        printf("rien n'est initialisé");
    while (arr[i] != '\0')
        i++;
    printf("voici i%d et n%d\n", i, n);

}


int main()
{
    int n = 133;

    printf("%c", (unsigned char)n);
    return(0);
}