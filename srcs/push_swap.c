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

#include <stdio.h>
#include "push_swap.h"

/**
 * The sort function launch the adapted algorithm to sort stack_a with 
 * optional help from stack_b.
 * 
 * @param	t_stack **stack_a	-	Address of stack_a.
 * 
 * @param	t_stack **stack_b	-	Address of
 * 
 * @return	Nothing.
 */
static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(stack_a);
	if (size < 3)
	{
		// small algo
	}
	else if (size >= 3 && size < 100)
	{
		// medium algo
	}
	else
	{
		// big algo
	}
	
}

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
	// WIP
}

/**
 * Welcome to the main function of push_swap !
 */
int	main(void)
{
	// Try to do those fucking algos !
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	
	i = 100;
	stack_a = NULL;
	stack_b = NULL;
	while (i > 0)
	{
		ft_stack_addback(&stack_a, ft_stack_create(i));
		i--;
	}
	ft_stack_dispfrom_f(stack_a);
	ft_stack_dispfrom_f(stack_b);
	reverse_rotate_stack(&stack_a, NULL, "rra\n");
	ft_stack_dispfrom_f(stack_a);
	ft_stack_dispfrom_f(stack_b);
}
