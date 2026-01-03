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

/* Error handling functions */
void	error_exit(void);
void	clean_exit(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);
void	free_stack(t_stack *stack);

/* Stack creation and validation */
t_stack	*create_and_init_stack(int capacity);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

/* Swap operations */
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* Push operations */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

/* Rotate operations */
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* Reverse rotate operations */
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Sorting functions */
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	handle_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		find_min_position(t_stack *stack);

/* Radix sort functions */
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	normalize_array(int *arr, int size);
void	sort_temp_array(int *temp, int size);
void	assign_ranks(int *arr, int *temp, int size);

#endif
