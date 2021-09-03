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

int	test(int i)
{
	printf("%d\n", i);
	if (i > 0)
		test(i - 1);
	printf("%d\n", i);
	return (1);
}

/**
 * Welcome to the main function of push_swap !
 */
int	main(void)
{
	// Try to do those fucking algos !
	int value;
	int	*a;
	int	*temp;

	value = 5;
	a = &value;
	temp = a;
	a = NULL;
	printf("%d\n", *temp);
	return (0);
}
