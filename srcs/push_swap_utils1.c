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

#include <stdio.h>
#include "push_swap.h"

/* Some utils functions here. */

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
 * !It's a norm function! 
 * 
 * The fill_lstchunk_util function add back to the list of chunk 
 * the created chunk and pass all pointer to NULL.
 * 
 * @param	t_lstchunk **lstchunk	-	List of chunk where add the 
 * 									new chunk.
 * 
 * @param	t_chunk **chunk	-	Chunk which will be in the new node.
 * 
 * @param	t_stack **values	-	All numbers contained in the chunk.
 */
static void	fill_lstchunk_util(t_lstchunk **lstchunk, t_chunk **chunk,
	t_stack **values)
{
	(*chunk)->values = *values;
	ft_lstchunk_addback(lstchunk, ft_lstchunk_create(*chunk));
	*chunk = NULL;
	*values = NULL;	
}
/**
 * The fill_lstchunk function fill the list of chunks using a sorted 
 * version of the stack_a. To define the size of a chunk we use 
 * CHUNK_SIZE defined in push_swap.h. The function return the first 
 * node of the list.
 * 
 * @param	t_lstchunk **lstchunk	-	List of chunk to fill in.
 * 
 * @param	t_stack *stack_a	-	Pointer to the first node of stack_a.
 * 
 * @return	Pointer to the first node of the lstchunk.
 */
t_lstchunk	*fill_lstchunk(t_lstchunk **lstchunk, t_stack *stack_a)
{
	t_stack	*copy;
	t_chunk	*chunk;
	t_stack	*values;
	int		i;

	copy = ft_stack_duplicate(stack_a);
	ft_stack_sort(&copy);
	i = 0;
	chunk = NULL;
	values = NULL;
	while (i < ft_stack_size(copy))
	{
		if (!chunk)
			chunk = ft_chunk_create(i / CHUNK_SIZE + 1, NULL);
		ft_stack_addback(&values, ft_stack_create(copy->integer));
		i++;
		if (copy->next)
			copy = copy->next;
		if ((i % CHUNK_SIZE == 0 && chunk != NULL)
			|| i == ft_stack_size(copy))
			fill_lstchunk_util(lstchunk, &chunk, &values);
	}
	ft_stack_clear(&copy);
	return (*lstchunk);
}

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
