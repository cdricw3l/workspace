/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:19:53 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 10:45:36 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define PID_MAX 100000

typedef struct s_pid
{
	int pid;
	char *str;
} t_pid ;

void	ft_printbit(int n);
void	ft_send_bit_to_pid(int n, int pid, int ms);
int		ft_bit_to_int(int *arr_bit);
int 	ft_strlen(char *str);
char 	*str_joint(char *str, char c);
int 	int_arr_len(int *arr);
int 	*add_nb(int *arr, int n);
int    	**ft_clean_arr(int *arr[], int i);
int 	**ft_int_bzero(int *arr[PID_MAX]);
int 	*ft_bzero(int *arr);
int 	ft_print_arr(int *arr);
void 	send_end_signal(int pid, int ms);

#endif