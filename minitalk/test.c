/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:49:59 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 15:36:43 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int **arr;

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
void try(int **arr, int n)
{
    (void)n;
    ft_bzero(arr[0]);
    printf("%d\n", arr[0]== NULL);
    //add_nb(arr[0], n);
}

int main()
{
    arr = malloc(sizeof(char *) * (0));
    arr[0] = NULL;
	if(!arr)
        return(0);
    try(arr, 10);
    
    return(0);
}