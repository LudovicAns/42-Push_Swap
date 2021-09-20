/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:19:31 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/20 01:19:31 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Need documentation.
 */
void	rotate_to_sort(t_stack **stack_a, t_stack *limits)
{
	t_stack	*copy;
	int		integer;
	int		index;

	copy = ft_stack_copy(*stack_a);
	ft_stack_addfront(&copy, ft_stack_create(limits->integer));
	ft_stack_sort(&copy);
	integer = ft_stack_getvalue(copy, ft_stack_find(copy, limits->integer) - 1);
	ft_stack_clear(&copy);
	index = ft_stack_find(*stack_a, integer);
	if (integer == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_getlast(*stack_a)->integer != integer)
		{
			rotate_stack(stack_a, NULL, "ra\n");
			*stack_a = ft_stack_getfirst(*stack_a);
		}
			
	else
		while (ft_stack_getlast(*stack_a)->integer != integer)
			reverse_rotate_stack(stack_a, NULL, "rra\n");
			
}

/**
 * Need documentation.
 */
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits)
{
	redefine_limits(&limits, *stack_b, 0);
	while (ft_stack_hasbigger(*stack_b, limits->next->integer))
	{
		if ((*stack_b)->integer == ft_stack_getmin(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			if (!*stack_b)
				return ;
			if ((*stack_b)->integer != ft_stack_getmin(*stack_b)
				&& (*stack_b)->integer <= limits->next->integer)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, NULL, "ra\n");
		}
		else if ((*stack_b)->integer > limits->next->integer)
		{
			push_stack(stack_b, stack_a, "pa\n");
		}
		else
			rotate_stack(stack_b, NULL, "rb\n");
	}
}

/**
 * Need documentation.
 */
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits)
{
	t_stack	*copy;

	copy = ft_stack_copy(*stack_b);
	ft_stack_sort(&copy);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->integer == copy->integer)
		{
			push_stack(stack_b, stack_a, "pa\n");
			copy = copy->next;
			 if (ft_stack_size(*stack_b) && (*stack_b)->integer != copy->integer
				&& (*stack_b)->integer != ft_stack_getmax(*stack_b))
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, NULL, "ra\n");
		}
		else if ((*stack_b)->integer == ft_stack_getmax(*stack_b))
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, NULL, "rb\n");
	}
	while (ft_stack_getlast(*stack_a)->integer != limits->next->integer)
		rotate_stack(stack_a, NULL, "ra\n");
	limits->next->integer = get_next_value(*stack_a, &limits);
	ft_stack_clear(&copy);
}

/**
 * Need documentation
 */
int	get_next_value(t_stack *stack_a, t_stack **limits)
{
	t_stack	*copy;
	int		index;
	int		min;

	copy = ft_stack_copy(stack_a);
	ft_stack_sort(&copy);
	index = ft_stack_find(copy, (*limits)->next->integer);
	min = ft_stack_getvalue(copy, index);
	if (min == ft_stack_getlast(copy)->integer)
	{
		ft_stack_clear(&copy);
		return (min);
	}
	else
		min = ft_stack_getvalue(copy, index + 1);
	ft_stack_clear(&copy);
	return (min);
}
