/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:19:53 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/08 16:17:05 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	ft_printbit(int n);
void	ft_send_bit_to_pid(int n, int pid, int ms);
int		ft_bit_to_int(int *arr_bit);
int 	ft_strlen(char *str);
char 	*str_joint(char *str, char c);
void 	send_end_signal(int pid, int ms);
void 	send_separator_signal(int pid, int ms);

#endif