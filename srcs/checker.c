/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:02:28 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/22 13:02:28 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The exit_checker function allow to exit checker properly. 
 * It frees all malloced variables and print associated message using 
 * status variable.
 * 
 * @param	t_stack	**stack_a	-	Address to the pointer of stack_a.
 * 
 * @param	t_stack	**stack_b	-	Address to the pointer of stack_b.
 * 
 * @param	t_list	**instructions	-	Address to the pointer of list of 
 * 									instructions.
 * 
 * @param	int status	-	Exit status value. (-1 or 0 or 1).
 * 
 * @return	Nothing.
 */
static void	exit_checker(t_stack **stack_a, t_stack **stack_b,
	t_list **instructions, int status)
{
	if (*stack_a)
		ft_stack_clear(stack_a);
	if (stack_b && *stack_b)
		ft_stack_clear(stack_b);
	if (*instructions)
	{
		while (*instructions)
			ft_lstremove(instructions);
	}
	if (status == -1)
		ft_putstr_fd("Error\n", STDERR);
	else if (!status)
		ft_putstr_fd("KO\n", STDOUT);
	else if (status == 1)
	{
		ft_putstr_fd("OK\n", STDOUT);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

/**
 * The fill_instructions function add all instruction runned by push_swap 
 * and put them inside the list of instructions.
 * 
 * @param	t_list **instructions	-	Address to the pointer of the list
 * 									of instructions.
 * 
 * @param	t_stack **stack_a	-	Address to the pointer of stack_a.
 * 
 * @return	Nothing.
 */
static void	fill_instructions(t_list **instructions, t_stack **stack_a)
{
	char	*line;
	t_list	*new_node;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!(!ft_strcmp("sa\0", line) || !ft_strcmp("sb\0", line)
				|| !ft_strcmp("ss\0", line) || !ft_strcmp("pa\0", line)
				|| !ft_strcmp("pb\0", line) || !ft_strcmp("ra\0", line)
				|| !ft_strcmp("rb\0", line) || !ft_strcmp("rr\0", line)
				|| !ft_strcmp("rra\0", line) || !ft_strcmp("rrb\0", line)
				|| !ft_strcmp("rrr\0", line)))
			exit_checker(stack_a, NULL, instructions, -1);
		new_node = ft_lstnew(ft_strdup(line));
		if (line)
		{
			free(line);
			line = NULL;
		}
		if (!new_node)
			exit_checker(stack_a, NULL, instructions, 0);
		ft_lstadd_back(instructions, new_node);
	}
	if (line)
		free(line);
}

/**
 * The call_instruction function call the given instruction.
 * 
 * @param	t_stack **stack_a	-	Address to the pointer of stack_a.
 * 
 * @param	t_stack **stack_b	-	Address to the pointer of stack_b.
 * 
 * @param	char *instruction	-	Name of the instruction.
 * 
 * @return	Nothing.
 */
static void	call_instruction(t_stack **stack_a, t_stack **stack_b,
	char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		swap_stack(*stack_a, NULL, NULL);
	if (!ft_strcmp("sb", instruction))
		swap_stack(*stack_b, NULL, NULL);
	if (!ft_strcmp("ss", instruction))
		swap_stack(*stack_a, *stack_b, NULL);
	if (!ft_strcmp("pa", instruction))
		push_stack(stack_b, stack_a, NULL);
	if (!ft_strcmp("pb", instruction))
		push_stack(stack_a, stack_b, NULL);
	if (!ft_strcmp("ra", instruction))
		rotate_stack(stack_a, NULL, NULL);
	if (!ft_strcmp("rb", instruction))
		rotate_stack(stack_b, NULL, NULL);
	if (!ft_strcmp("rr", instruction))
		rotate_stack(stack_a, stack_b, NULL);
	if (!ft_strcmp("rra", instruction))
		reverse_rotate_stack(stack_a, NULL, NULL);
	if (!ft_strcmp("rrb", instruction))
		reverse_rotate_stack(stack_b, NULL, NULL);
	if (!ft_strcmp("rrr", instruction))
		reverse_rotate_stack(stack_a, stack_b, NULL);
}

/**
 * The do_instructions execute all instructions in the list.
 * 
 * @param	t_stack **stack_a	-	Address to the pointer of stack_a.
 * 
 * @param	t_stack **stack_b	-	Address to the pointer of stack_b.
 * 
 * @param	t_list *instructions	-	First node of instruction list.
 * 
 * @return	Nothing.
 */
static void	do_instructions(t_stack **stack_a, t_stack **stack_b,
	t_list *instructions)
{
	while (instructions)
	{
		call_instruction(stack_a, stack_b, (char *)instructions->content);
		instructions = instructions->next;
	}
}

/**
 * Welcome to the main function of checker !
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	instructions = NULL;
	move_args_to_stack(argv, &stack_a);
	fill_instructions(&instructions, &stack_a);
	do_instructions(&stack_a, &stack_b, instructions);
	if (ft_stack_issorted(&stack_a) && !stack_b)
		exit_checker(&stack_a, &stack_b, &instructions, 1);
	exit_checker(&stack_a, &stack_b, &instructions, 0);
	return (0);
}
