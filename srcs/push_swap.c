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
 * Welcome to the main function of push_swap !
 */
int	main(int argc, char **argv)
{
	// Try to do those fucking algos !
	t_stack	*stack_a;

	stack_a = NULL;
	ft_putnbr_fd(argc - 1, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	move_args_to_stack(argv, &stack_a);
	ft_stack_dispfrom_f(&stack_a);

	ft_stack_sort(&stack_a);


	ft_stack_dispfrom_f(&stack_a);
	return (0);
}
