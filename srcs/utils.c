/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:33:30 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/29 18:33:30 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* Some utils functions here. */

/**
 * The exit_prog function allow to exit the push_swap program properly.
 * First it will try to free the two stacks (a and b) then it will exit
 * using exit_status.
 * 	1	-	In case of success.
 * 	0	-	In case of failure.
 * 
 * @param	t_stack **stack_a	-	Stack a.
 * 
 * @param	t_stack **stack_b	-	Stack b.
 * 
 * @param	int exit_status	-	Value of exit (0 or 1).
 */
void	exit_prog(t_stack **stack_a, t_stack **stack_b, int exit_status)
{
	if (stack_a)
		ft_stack_clear(stack_a);
	if (stack_b)
		ft_stack_clear(stack_b);
	if (!exit_status)
	{
		ft_putstr_fd("Error\n", STDOUT);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/**
 * Need documentation.
 */
void	move_args_to_stack(char **args, t_stack **stack_a)
{
	long long int		integer;
	t_stack				*new_item;
	int					i;
	char				**splited;

	i = 0;
	splited = ft_split(args[1], ' ');
	while (splited[i])
	{
		if (!ft_str_isnumeric(splited[i]))
			exit_prog(stack_a, NULL, 0);
		integer = ft_atoi(splited[i]);
		i++;
		if (!ft_isnormal_int(integer))
			exit_prog(stack_a, NULL, 0);
		new_item = ft_stack_create(integer);
		if (!new_item)
			exit_prog(stack_a, NULL, 0);
		ft_stack_addback(stack_a, new_item);
	}
	if (ft_stack_has_dup(stack_a))
		exit_prog(stack_a, NULL, 0);
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
