/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:13:05 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/21 20:13:05 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The get_chunk_id function determine which chunk the program need 
 * to use to find the next number to push in stack_b.
 * For that, the function count the size of the stack_b and divide it by 
 * CHUNK_SIZE + 1 defined in push_swap.h.
 * 
 * @param	t_stack *stack_b	-	Pointer to the stack_b.
 * 
 * @return The id of the chunk who need to be used.
 */
int	get_chunk_id(t_stack *stack_b)
{
	return (ft_stack_size(stack_b) / CHUNK_SIZE + 1);
}

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
 * This function is a part of push_nb_on_top() only !
 * 
 * The assign_instruction_name function determine the name of instruction
 * depending on stack_name. 
 * For example: if stack_name = 'a', *rx = "ra\n" and *rrx = "rra\n".
 * 
 * @param	char stack_name	-	Name of the stack ('a' or 'b').
 * 
 * @param	char **rx	-	Address of string rx.
 * 
 * @param	char **rrx	-	Address of string rrx.
 * 
 * @result	Nothing. Values are directly assigned in string's address.
 */
static void	assign_instruction_name(char stack_name, char **rx, char **rrx)
{
	if (stack_name == 'a')
	{
		*rx = "ra\n";
		*rrx = "rra\n";
	}
	else
	{
		*rx = "rb\n";
		*rrx = "rrb\n";
	}
}

/**
 * The push_nb_on_top function push the given number at the top of 
 * stack in the most optimized way by using rotate or reverse rotate 
 * instructions.
 * 
 * @param	t_stack **stack	-	Stack treated.
 * 
 * @param	int num	-	Number to push at the top.
 * 
 * @param	char stack_name	-	'a' to stack_a or 'b' to stack_b.
 */
void	push_nb_on_top(t_stack **stack, int num, char stack_name)
{
	int		index;
	char	*rx;
	char	*rrx;

	index = ft_stack_find(*stack, num);
	if (index == -2147483648)
		return ;
	assign_instruction_name(stack_name, &rx, &rrx);
	if (index <= ft_stack_size(*stack) / 2)
	{
		while (ft_stack_getfirst(*stack)->integer != num)
			rotate_stack(stack, NULL, rx);
	}
	else
	{
		while (ft_stack_getfirst(*stack)->integer != num)
			reverse_rotate_stack(stack, NULL, rrx);
	}
}

/**
 * The get_boundary function determines the nearest and greatest number 
 * of given nearest number.
 * 
 * @param	t_stack *stack_b	-	Pointer to stack_b.
 * 
 * @param	int nearest	-	Nearest number founded in stack_a using 
 * 						chunk's values.
 * 
 * @result	Superior boundary of given nearest number.
 */
int	get_boundary(t_stack *stack_b, int nearest)
{
	t_stack *tmp;
	int	diff;
	int	num;

	diff = INTMAX;
	num = 0;
	stack_b = ft_stack_getfirst(stack_b);
	tmp = stack_b;
	while (stack_b)
	{
		if (nearest - stack_b->integer > 0
			&& nearest - stack_b->integer < diff)
		{
			diff = nearest - stack_b->integer;
			num = stack_b->integer;
		}
		stack_b = stack_b->next;
	}
	if (num == 0)
		num = ft_stack_getmax(tmp);
	return (num);
}
