/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:22:31 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/28 17:22:31 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Some utils functions for push_swap.c here. */

/**
 * The push_min_value function push the lowest integer of stack_x to 
 * the stack_y (using push_swap rules).
 * 
 * @param	t_stack **stack_x	-	Address of the stack used to push.
 * 
 * @param	t_stack **stack_y	-	Address of the pushed stack.
 * 
 * @result	Nothing.
 */
void	push_min_value(t_stack **stack_x, t_stack **stack_y)
{
	int	min;

	min = ft_stack_getmin(*stack_x);
	while ((*stack_x)->integer != min)
	{
		if ((*stack_x)->integer != min && (*stack_x)->next->integer != min)
		{
			reverse_rotate_stack(stack_x, NULL, "rra\n");
			*stack_x = ft_stack_getfirst(*stack_x);
		}
		else
		{
			rotate_stack(stack_x, NULL, "ra\n");
			*stack_x = ft_stack_getfirst(*stack_x);
		}
	}
	push_stack(stack_x, stack_y, "pb\n");
}

/**
 * Need documentation.
 */
int	count_diff_limits(t_stack *stack_a, t_stack *limits)
{
	t_stack	*copy;
	int		min_index;
	int		max_index;

	copy = ft_stack_duplicate(stack_a);
	ft_stack_sort(&copy);
	min_index = ft_stack_find(copy, limits->integer);
	max_index = ft_stack_find(copy, limits->next->integer);
	ft_stack_clear(&copy);
	return (max_index - min_index + 1);
}

/**
 * Need documentation.
 */
void	redefine_limits(t_stack **limits, t_stack *stack_a, int mode)
{
	t_stack	*copy;
	int		min_index;
	int		max_index;
	int		new_limit;

	copy = ft_stack_copy(stack_a);
	ft_stack_sort(&copy);
	if (mode)
	{
		min_index = ft_stack_find(copy, (*limits)->integer);
		max_index = ft_stack_find(copy, (*limits)->next->integer);
		new_limit = ft_stack_getvalue(copy,
						((max_index - min_index) / 2 + min_index + 3));
	}
	else
		new_limit = ft_stack_getvalue(copy, ft_stack_size(copy) / 2);
	ft_stack_addback(limits, ft_stack_create(new_limit));
	ft_stack_sort(limits);
	ft_stack_clear(&copy);
}

/**
 * Need documentation.
 */
int	get_hold_first(t_stack *stack_a, t_stack *limits)
{
	int	first;
	int	min;
	int	max;

	min = limits->integer;
	max = limits->next->integer;
	first = 0;
	while (stack_a)
	{
		if (stack_a->integer >= min && stack_a->integer <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

/**
 * Need documentation.
 */
void	split_a_to_b_with_limits(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits)
{
	int	item_to_split;
	int	first;

	item_to_split = count_diff_limits(*stack_a, limits);
	while (ft_stack_size(*stack_b) < item_to_split)
	{
		first = get_hold_first(*stack_a, limits);
		while (first--)
			rotate_stack(stack_a, NULL, "ra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
	
}
