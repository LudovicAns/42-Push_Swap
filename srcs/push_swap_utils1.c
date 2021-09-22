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
 * This function is a part of get_nearest() only !
 * 
 * The get_nearest_from_bottom return the nearest number from 
 * the bottom of stack which is also present in chunk.
 * 
 * @param	t_stack *stack	-	Stack to search.
 * 
 * @param	t_chunk *chunk	-	Chunk used.
 * 
 * @return	Nearest number from bottom.
 */
static int get_nearest_from_bottom(t_stack *stack, t_chunk *chunk)
{
	stack = ft_stack_getlast(stack);
	while (stack)
	{
		if (ft_stack_contain(chunk->values, stack->integer))
			return (stack->integer);
		stack = stack->previous;
	}
	return (0);
}

/**
 * This function is a part of get_nearest() only !
 * 
 * The get_nearest_from_top return the nearest number from 
 * the top of stack which is also present in chunk.
 * 
 * @param	t_stack *stack	-	Stack to search.
 * 
 * @param	t_chunk *chunk	-	Chunk used.
 * 
 * @return	Nearest number from top.
 */
static int get_nearest_from_top(t_stack *stack, t_chunk *chunk)
{
	stack = ft_stack_getfirst(stack);
	while (stack)
	{
		if (ft_stack_contain(chunk->values, stack->integer))
			return (stack->integer);
		stack = stack->next;
	}
	return (0);
}

/**
 * The get_nearest function search in stack_a a number who is in 
 * chunk's values. It compare first the nearest by the top of stack_a 
 * and secondly by the bottom of stack_a. 
 * It will count needed actions to move each of them to the top of the 
 * stack. The nearest who has the less actions count will be
 * returned. 
 * If action count is equal for each of them, the nearest who is the most 
 * on the top of the stack will be returned.
 * 
 * @param	t_stack *stack_a	-	pointer to stack_a.
 * 
 * @param	t_chunk	*chunk	-	Chunk used to search nearest.
 * 
 * @param	int *nearest	-	Pointer to the value of the nearest.
 * 
 * @return	The nearest integer in stack_a also contained in the given 
 * 			chunk. And the pointer to nearest is actualized.
 */
int	get_nearest(t_stack *stack_a, t_chunk *chunk, int *nearest)
{
	int stack_size;
	int	hold_first_idx;
	int	hold_second_idx;

	stack_size = ft_stack_size(stack_a);
	hold_first_idx = ft_stack_find(stack_a,
		get_nearest_from_top(stack_a, chunk));
	hold_second_idx = ft_stack_find(stack_a,
		get_nearest_from_bottom(stack_a, chunk));
	if (hold_first_idx <= (stack_size - hold_second_idx))
	{
		hold_first_idx = ft_stack_getvalue(stack_a, hold_first_idx);
		*nearest = hold_first_idx;
		return (hold_first_idx);
	}
	else
	{
		hold_second_idx = ft_stack_getvalue(stack_a, hold_second_idx);
		*nearest = hold_second_idx;
		return (hold_second_idx);
	}
}
