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

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 20
# endif

/* Function from push_swap_utils1.c */

void		push_min_value(t_stack **stack_x, t_stack **stack_y);
t_lstchunk	*fill_lstchunk(t_lstchunk **lstchunk, t_stack *stack_a);
int			get_chunk_id(t_stack *stack_b);

#endif
