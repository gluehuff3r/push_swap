/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:22:15 by haabu-sa          #+#    #+#             */
/*   Updated: 2026/01/03 15:31:12 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
}	t_stack;

void	erorr_e(void);
void	clean_e(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);
void	free_stack(t_stack *stack);
t_stack	*create_stack(int capacity);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		find_pos(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	index_array(int *arr, int size);
void	sort_temp(int *temp, int size);
void	assign_ranks(int *arr, int *temp, int size);

#endif
