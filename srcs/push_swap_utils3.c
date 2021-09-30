/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:47:27 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/23 15:37:54 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The get_chunk_size function return size of one chunk depending on total 
 * size of the stack_a.
 * 
 * @param	t_stack *stack_a	-	Pointer to stack_a.
 * 
 * @return	Size of one chunk.
 */
int	get_chunk_size(t_stack *stack_a)
{
	if (ft_stack_size(stack_a) >= 500)
		return (500 / 11);
	else
		return (20);
}
