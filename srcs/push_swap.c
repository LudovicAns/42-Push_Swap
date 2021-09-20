/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:35:35 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/28 16:35:35 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The small_algo_sort function sort the stack_a without using another stack.
 * 
 * @param	t_stack	**stack_a	-	Address of the stack_a to sort it. 
 * 
 * @result	Nothing.
 */
static void	small_algo_sort(t_stack **stack_a)
{
	int	min;
	int	max;

	min = ft_stack_getmin(*stack_a);
	max = ft_stack_getmax(*stack_a);
	while (!ft_stack_issorted(stack_a))
	{
		if ((*stack_a)->integer != min
			&& (*stack_a)->next->integer == max)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else if ((*stack_a)->integer == max
			&& (*stack_a)->next->integer == min)
			rotate_stack(stack_a, 0, "ra\n");
		else
			swap_stack(*stack_a, 0, "sa\n");
	}
}

/**
 * The medium_algo_sort function sort the stack_a using stack_b and 
 * small_algo_sort function.
 * 
 * @param	t_stack **stack_a	-	Address of the stack_a to sort it.
 * 
 * @param	t_stack **stack_b	-	Address of the stack_b used to help 
 * 								sorting stack_a.
 */
static void	medium_algo_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		push_min_value(stack_a, stack_b);
	small_algo_sort(stack_a);
	while (ft_stack_size(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}

/**
 * Need documentation.
 */
static void	big_algo_sort(t_stack **stack_a, t_stack **stack_b,
	t_stack **limits, int i)
{
	if (ft_stack_size(*limits) == 1)
	{
		ft_stack_clear(limits);
		return ;
	}
	if (ft_stack_size(*limits) == 2
		&& count_diff_limits(*stack_a, *limits) >= CHUNK_SIZE)
	{
		redefine_limits(limits, *stack_a, 1);
	}
	if (!ft_stack_size(*stack_b))
	{
		split_a_to_b_with_limits(stack_a, stack_b, *limits);
		rotate_to_sort(stack_a, *limits);
	}
	if (ft_stack_size(*stack_b) >= CHUNK_SIZE)
		merge_half_to_a(stack_a, stack_b, *limits);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *limits);
		ft_stack_remove(limits);
	}
	big_algo_sort(stack_a, stack_b, limits, ++i);
}

/**
 * The sort function launch the adapted algorithm to sort stack_a with 
 * optional help from stack_b.
 * 
 * @param	t_stack **stack_a	-	Address of stack_a.
 * 
 * @param	t_stack **stack_b	-	Address of stack_b.
 * 
 * @return	Nothing.
 */
static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limits;
	int		size;
	int		min;
	int		max;

	size = ft_stack_size(*stack_a);
	min = ft_stack_getmin(*stack_a);
	max = ft_stack_getmax(*stack_a);
	if (size <= 3)
		small_algo_sort(stack_a);
	else if (size <= 5)
		medium_algo_sort(stack_a, stack_b);
	else
	{
		limits = ft_stack_create(min);
		ft_stack_addback(&limits, ft_stack_create(max));
		big_algo_sort(stack_a, stack_b, &limits, 0);
	}
	
}

/**
 * Welcome to the main function of push_swap !
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	move_args_to_stack(argv, &stack_a);
	if (!ft_stack_issorted(&stack_a))
		sort(&stack_a, &stack_b);
	ft_stack_dispfrom_f(stack_a);
	exit_prog(&stack_a, &stack_b, 1);
	return (0);
}
