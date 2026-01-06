/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:22:15 by haabu-sa          #+#    #+#             */
/*   Updated: 2026/01/03 16:51:32 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_temp(int *temp, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (temp[j] > temp[j + 1])
			{
				t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	assign_ranks(int *arr, int *temp, int size)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (temp[j] < arr[i])
				rank++;
			j++;
		}
		arr[i] = rank;
		i++;
	}
}

void	index_array(int *arr, int size)
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return ;
	while (i < size)
	{
		temp[i] = arr[i];
		i++;
	}
	sort_temp(temp, size);
	assign_ranks(arr, temp, size);
	free(temp);
}

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;
	int size;
	
	max = stack->numbers[0];
	i = 1;
	size = stack->size;
	while (i < size)
	{
		if (stack->numbers[i] > max)
			max = stack->numbers[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_array(stack_a->numbers, stack_a->size);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = stack_a->size;
		j = 0;
		while (j < size)
		{
			if (((stack_a->numbers[0] >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, 1);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
