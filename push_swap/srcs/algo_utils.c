/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/26 16:10:51 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_high(int *arr, int size)
{
	int	i;
	int	high;

	i = 1;
	high = arr[0];
	while (i < size)
	{
		if (arr[i] > high)
			high = arr[i];
		i++;
	}
	return (high);
}

int	get_low(int *arr, int size)
{
	int	i;
	int	low;

	i = 1;
	low = arr[0];
	while (i < size)
	{
		if (arr[i] < low)
			low = arr[i];
		i++;
	}
	return (low);
}

void	ft_quick_swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int	ft_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high - 1];
	i = low - 1;
	j = low - 1;
	while (j < high - 1)
	{
		if (arr[i] < pivot)
		{
			i++;
			j++;
		}
		else
			j++;
		if (arr[j] < arr[i])
			ft_quick_swap(arr, j++, i);
	}
	return (i);
}

void	ft_qsort_int(int *base, int low, int high)
{
	int	i;

	if (low < high - 1)
	{
		i = ft_partition(base, low, high);
		ft_qsort_int(base, 0, i);
		ft_qsort_int(&base[i], 0, high - i);
	}
}

// int main(void)
// {
// 	int len[]= {-1, 33, 79, 2, 4, 5, '\0'};
// 	int size = ft_size_of_array(len);
// 	ft_qsort_int(len, 0, size);
// 	ft_print_arr(len);
// 	return (0);
// }