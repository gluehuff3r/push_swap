/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:22:15 by haabu-sa          #+#    #+#             */
/*   Updated: 2026/01/03 16:57:36 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(char **num, int count, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (num[i])
		i++;
	if (i == 0)
	{
		if (count == 1)
			free_split(num);
		error_exit();
	}
	*a = create_and_init_stack(i);
	*b = create_and_init_stack(i);
	if (!*a || !*b)
	{
		if (count == 1)
			free_split(num);
		error_exit();
	}
}

static void	fill_stack(char **num, int count, t_stack **a, t_stack **b)
{
	int	j;

	if (count == 1)
		j = 0;
	else
		j = 1;
	while (num[j])
	{
		if (!is_number(num[j]))
		{
			if (count == 1)
				free_split(num);
			clean_exit(*a, *b);
		}
		(*a)->numbers[(*a)->size++] = ft_atoi(num[j]);
		j++;
	}
	if (has_duplicates(*a))
	{
		if (count == 1)
			free_split(num);
		clean_exit(*a, *b);
	}
}

static void	handle_single_argument(char *arg, t_stack **a, t_stack **b)
{
	char	**num;
	int		i;

	i = 0;
	while (arg[i])
		i++;
	while (i > 0 && arg[i - 1] == ' ')
		i--;
	if (i == 0)
		error_exit();
	arg[i] = '\0';
	num =ft_split(arg, ' ');
	if (!num)
		error_exit();
	init_stacks(num, 1, a, b);
	fill_stack(num, 1, a, b);
	free_split(num);
}

static void	handle_multiple_arguments(int argc, char **argv, t_stack **a,
		t_stack **b)
{
	init_stacks(argv, argc, a, b);
	fill_stack(argv, argc, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		handle_single_argument(argv[1], &stack_a, &stack_b);
	else
		handle_multiple_arguments(argc, argv, &stack_a, &stack_b);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
