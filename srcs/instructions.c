/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:33:20 by lanselin          #+#    #+#             */
/*   Updated: 2021/08/29 18:33:20 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The push_swap project use 11 differents instructions to sort a stack with 
 * an other stack (the other stack not necessary used).
 * 
 * Those 11 instructions can be rallied in 4 family which are:
 * 	- Swap family :				sa, sb, ss
 * 	- Push family :				pa, pb
 * 	- Rotate family :			ra, rb, rr
 * 	- Reverse Rotate family:	rra, rrb, rrr
 * 
 * What does each family ?
 * 
 * Swap family:
 * 	A swap instruction allow you to invert the two first item in a specified 
 * 	stack (ss instruction do this in the two stacks in the same time).
 * 
 * Push family:
 * 	A push instruction allow you to send the first item of the opposite stack 
 * 	to the specified stack (for example, pa take the first item in b and move 
 * 	it to a).
 * 
 * Rotate family:
 * 	A rotate instruction shift up the specified stack. So the first item 
 * 	become the last item of the stack (rr do this in the two stacks in 
 * 	the same time).
 * 
 * Reverse Rotate family:
 * 	A rotate instruction shift down the specified stack. So the last item 
 * 	become the first item of the stack (rrr do this in the two stacks in 
 * 	the same time).
 */

#include "utils.h"

/**
 * The swap_stack function allow to perform those instructions:
 * 	- sa
 * 	- sb
 * 	- ss
 * 
 * @param	t_stack *mandatory	-	The stack to swap.
 * 
 * @param	t_stack *optional	-	The other stack to swap. (Optional)
 * 
 * @param	char *info	-	The information about the swap action. 
 * 						For example, info can be equal to "sa" or "ss".
 * 
 * @return	Nothing.
 */
void	swap_stack(t_stack *mandatory, t_stack *optional, char *info)
{
	t_stack	*stack;

	stack = ft_stack_getfirst(mandatory);
	ft_swapint(&stack->integer, &stack->next->integer);
	if (optional)
	{
		stack = ft_stack_getfirst(optional);
		ft_swapint(&stack->integer, &stack->next->integer);
	}
	ft_putstr_fd(info, STDOUT);
}

/**
 * The push_stack function allow to perform those instructions:
 * 	- pa
 * 	- pb
 * 
 * @param	t_stack **from_stack	-	The stack to take the first item.
 * 
 * @param	t_stack **to_stack	-	The stack to push the item.
 * 
 * @param	char *info	-	The information about the push action. 
 * 						For example, info can be equal to "pa" or "pb".
 * 
 * @return	Nothing.
 */
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *info)
{
	t_stack	*item;

	if (!(*from_stack))
		return ;
	item = ft_stack_getfirst(*from_stack);
	ft_stack_addfront(to_stack, ft_stack_create(item->integer));
	*from_stack = item;
	ft_stack_remove(from_stack);
	ft_putstr_fd(info, STDOUT);
}

/**
 * The rotate_stack function allow to perform those instructions:
 * 	- ra
 * 	- rb
 * 	- rr
 * 
 * @param	t_stack **mandatory	-	The stack to rotate.
 * 
 * @param	t_stack **optional	-	The other stack to rotate. (Optional)
 * 
 * @param	char *info	-	The informations about the rotate action.
 * 						For example, info can be equal to "ra" or "rr"
 * 
 * @return	Nothing.
 */
void	rotate_stack(t_stack **mandatory, t_stack **optional, char *info)
{
	int		save;
	t_stack	*item;

	item = ft_stack_getfirst(*mandatory);
	save = item->integer;
	*mandatory = item;
	ft_stack_remove(mandatory);
	ft_stack_addback(mandatory, ft_stack_create(save));
	if (optional)
	{
		item = ft_stack_getfirst(*optional);
		save = item->integer;
		*optional = item;
		ft_stack_remove(optional);
		ft_stack_addback(optional, ft_stack_create(save));
	}
	ft_putstr_fd(info, STDOUT);
}

/**
 * The reverse_rotate_stack function allow to perform those instructions:
 * 	- rra
 * 	- rrb
 * 	- rrr
 * 
 * @param	t_stack **mandatory	-	The stack to reverse rotate.
 * 
 * @param	t_stack **optional	-	The other stack to reverse rotate. (Optional)
 * 
 * @param	char *info	-	The informations about the reverse rotate action.
 * 						For example, info can be equal to "rra" or "rrr"
 * 
 * @return	Nothing.
 */
void	reverse_rotate_stack(t_stack **mandatory, t_stack **optional,
			char *info)
{
	int		save;
	t_stack	*item;

	item = ft_stack_getlast(*mandatory);
	save = item->integer;
	ft_stack_remove(&item);
	ft_stack_addfront(mandatory, ft_stack_create(save));
	if (optional)
	{
		item = ft_stack_getlast(*optional);
		save = item->integer;
		ft_stack_remove(&item);
		ft_stack_addfront(optional, ft_stack_create(save));
	}
	ft_putstr_fd(info, STDOUT);
}
