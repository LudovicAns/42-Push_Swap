/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:33:59 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/29 18:33:59 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

/* Functions from instructions.c */
void	swap_stack(t_stack *mandatory, t_stack *optional, char *info);
void	push_stack(t_stack **from_stack, t_stack *to_stack, char *info);
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *info);
void	reverse_rotate_stack(t_stack **mandatory, t_stack **optional,
			char *info);

/* Functions from utils.c */
void	exit_prog(t_stack **stack_a, t_stack **stack_b, int exit_status);
void	move_args_to_stack(char **args, t_stack **stack_a);

#endif