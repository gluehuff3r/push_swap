/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:22:15 by haabu-sa          #+#    #+#             */
/*   Updated: 2026/01/03 16:53:12 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_and_init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = (int *)malloc(sizeof(int) * capacity);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	ft_bzero(stack->numbers, sizeof(int) * capacity);
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

static int	is_valid_number_format(char *str, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i])
		return (0);
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

int	is_number(char *str)
{
	int		i;
	long	num;
	int		sign;
	int		j;

	if (!is_valid_number_format(str, &i, &sign))
		return (0);
	num = 0;
	j = 0;
	while (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j])
	{
		if ((num > 2147483647 / 10) || (num == 2147483647 / 10 && (str[j]
					- '0') > 2147483647 % 10))
			return (0);
		num = num * 10 + (str[j] - '0');
		j++;
	}
	if ((sign == 1 && num > 2147483647) || (sign == -1 && (-num) < -2147483648))
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;
	int	size;
	
	i = 0;
	size = stack->size;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->numbers[i] == stack->numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	size;
	
	size = stack->size;
	i = 0;
	while (i < size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
