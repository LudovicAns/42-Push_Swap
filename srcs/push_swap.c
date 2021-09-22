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

static void big_algo_sort(t_stack **stack_a, t_stack **stack_b,
	int args_size)
{
	t_lstchunk	*lstchunk;
	int			nearest;

	lstchunk = NULL;
	lstchunk = fill_lstchunk(&lstchunk, *stack_a);
	nearest = 0;
	while (ft_stack_size(*stack_b) != args_size)
	{
		// 1.Find nearest number in stack_a and the chunk id get_chunk_id.
		// 2.Push it (in the most optimized way as possible) to the top of 
		//   the stack_a.
		push_nb_on_top(stack_a,
			get_nearest(*stack_a, ft_lstchunk_getchunk(lstchunk,
				get_chunk_id(*stack_b)), &nearest), 'a');
		// 3.Determine the superior born number of it.
		// 4.Push his superior born number to the top of the stack_b. (In 
		//   the most optimized way as possible again...)
		if (*stack_b)
			push_nb_on_top(stack_b, get_boundary(*stack_b, nearest), 'b');
		// 5.Push the nearest number to the stack_b.
		push_stack(stack_a, stack_b, "pb\n");
	}
	push_nb_on_top(stack_b, ft_stack_getmax(*stack_b), 'b');
	// 6.Push all numbers in stack_b directly in stack_a.
	while (*stack_b)
		push_stack(stack_b, stack_a, "pa\n");
	// 7. Good job, you sort the stack_a !
	ft_lstchunk_clear(&lstchunk);
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
	int	size;

	size = ft_stack_size(*stack_a);
	if (size < 3)
		small_algo_sort(stack_a);
	else if (size <= 5)
		medium_algo_sort(stack_a, stack_b);
	else
		big_algo_sort(stack_a, stack_b, ft_stack_size(*stack_a));
}

void	fill_stack(int from, int to, t_stack **stack)
{
	while (from != to)
	{
		ft_stack_addback(stack, ft_stack_create(from));
		if (from > to)
			from--;
		else
			from++;
	}
	ft_stack_addback(stack, ft_stack_create(from));
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
	exit_prog(&stack_a, &stack_b, 1);
	return (0);
}
