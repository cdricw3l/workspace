/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_arg_unit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:57 by cw3l              #+#    #+#             */
/*   Updated: 2024/11/18 16:13:02 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../include/push_swap.h"

int validation_arg_unit()
{
    char *arg = "10"; 
    ft_validation_arg(&arg);
    

    return (0);
}