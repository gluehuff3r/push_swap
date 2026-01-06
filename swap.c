/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:22:15 by haabu-sa          #+#    #+#             */
/*   Updated: 2026/01/03 16:35:11 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[1];
	stack_a->numbers[1] = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->numbers[0];
	stack_b->numbers[0] = stack_b->numbers[1];
	stack_b->numbers[1] = temp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
		small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
