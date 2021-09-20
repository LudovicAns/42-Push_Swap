/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:35:57 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/28 16:35:57 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes and definitions here. */
# include "libft.h"
# include "utils.h"

#include <stdio.h>

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 20
# endif

/* Functions from push_swap_utils1.c */

void	push_min_value(t_stack **stack_x, t_stack **stack_y);
int		count_diff_limits(t_stack *stack_a, t_stack *limits);
void	redefine_limits(t_stack **limits, t_stack *stack_a, int mode);
int		get_hold_first(t_stack *stack_a, t_stack *limits);
void	split_a_to_b_with_limits(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits);

/* Functions from push_swap_utils2.c */

void	rotate_to_sort(t_stack **stack_a, t_stack *limits);
void	merge_half_to_a(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits);
void	merge_sort_to_a(t_stack **stack_a, t_stack **stack_b,
	t_stack *limits);
int		get_next_value(t_stack *stack_a, t_stack **limits);

#endif
