/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:59:08 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/20 16:59:08 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/**
 * The ft_chunk_create function create a new chunk and return his address.
 * 
 * @param	int id	-	Unique id of the chunk.
 * 
 * @param	t_stack *values	-	Associated stack.
 * 
 * @return	Pointer to the new chunk.
 */
t_chunk	*ft_chunk_create(int id, t_stack *values)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk) * 1);
	if (!new_chunk)
		return (NULL);
	new_chunk->id = id;
	new_chunk->values = ft_stack_duplicate(values);
	return (new_chunk);
}

/**
 * The ft_chunk_remove function remove and free all variables inside a 
 * chunk.
 * 
 * @param	t_stack *chunk	-	Chunk to remove.
 * 
 * @return	Nothing.
 */
void	ft_chunk_remove(t_chunk *chunk)
{
	if (!chunk)
		return ;
	if (chunk->values)
		ft_stack_clear(&(chunk->values));
	free(chunk);
}
