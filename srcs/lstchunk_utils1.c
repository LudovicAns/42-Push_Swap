/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstchunk_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:21:06 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/20 17:21:06 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/**
 * The *ft_lstchunk_create function create a new list of chunk.
 * 
 * @param	t_chunk	*chunk -	Chunk to put in the first node.
 * 
 * @return	Pointer to the first node of the list.
 */
t_lstchunk	*ft_lstchunk_create(t_chunk *chunk)
{
	t_lstchunk	*new_node;

	new_node = (t_lstchunk *)malloc(sizeof(t_lstchunk) * 1);
	if (!new_node)
		return (NULL);
	new_node->actual = ft_chunk_create(chunk->id, chunk->values);
	new_node->next = NULL;
	new_node->previous = NULL;
	ft_chunk_remove(chunk);
	return (new_node);
}

/**
 * The ft_lstchunk_remove function delete a node from a list. It free the chunk 
 * inside and also free the node. After deletation, *lstchunk is 
 * redirected to the previous node if it exist else to the next node.
 * If any of them does not exist, the pointer on *lstchunk will be NULL;
 * 
 * @param	t_lstchunk **lstchunk	-	Address of the node to remove.
 * 
 * @return	Nothing.
 */
void	ft_lstchunk_remove(t_lstchunk **lstchunk)
{
	t_lstchunk	*node;

	if (!*lstchunk)
		return ;
	node = *lstchunk;
	ft_chunk_remove(node->actual);
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	if (node->previous)
		*lstchunk = node->previous;
	else
		*lstchunk = node->next;
	free(node);
}

/**
 * The ft_lstchunk_clear function remove all node from a list and free all 
 * of them. After deleting the address of the pointer to the first node 
 * is nullified.
 * 
 * @param	t_lstchunk **lstchunk	-	The list who must be cleared.
 * 
 * @return	Nothing.
 */
void	ft_lstchunk_clear(t_lstchunk **lstchunk)
{
	if (!lstchunk)
		return ;
	while (*lstchunk)
		ft_lstchunk_remove(lstchunk);
	lstchunk = NULL;
}

/**
 * The ft_lstchunk_addback function add the given node to the end of the 
 * list.
 * 
 * @param	t_lstchunk	-	Address of the pointer of the list.
 * 
 * @param	t_lstchunk	-	Node to add at the end of the list.
 * 
 * @return	Nothing.
 */
void	ft_lstchunk_addback(t_lstchunk **lstchunk, t_lstchunk *new)
{
	t_lstchunk	*node;

	if (!*lstchunk)
	{
		*lstchunk = new;
		return ;
	}
	node = *lstchunk;
	while (node->next)
		node = node->next;
	new->previous = node;
	node->next = new;
}

/**
 * The ft_lstchunk_getchunk function return the chunk contained 
 * in the list corresponding to the given id.
 * If the list does not contain a chunk with the given id, the 
 * function return NULL pointer.
 * 
 * @param	t_lstchunk *lstchunk	-	Pointer to the first node of 
 * 									the list.
 * 
 * @param	int id	-	id of the searched chunk in the list.
 * 
 * @return	The chunk with the searched id or NULL if id does not exist 
 * 			in the list.
 */
t_chunk	*ft_lstchunk_getchunk(t_lstchunk *lstchunk, int id)
{
	while (lstchunk)
	{
		if (lstchunk->actual->id == id)
			return (lstchunk->actual);
		lstchunk = lstchunk->next;
	}
	return (NULL);
}
