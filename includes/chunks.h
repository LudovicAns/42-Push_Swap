/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <lanselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:17:01 by lanselin          #+#    #+#             */
/*   Updated: 2021/09/23 15:17:01 by lanselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKS_H
# define CHUNKS_H

# include "libft.h"

typedef struct s_chunk
{
	int		id;
	t_stack	*values;
}	t_chunk;

typedef struct s_lstchunk
{
	struct s_lstchunk	*previous;
	t_chunk				*actual;
	struct s_lstchunk	*next;
}	t_lstchunk;

/* Functions from chunk_utils1.c */

t_chunk		*ft_chunk_create(int id, t_stack *values);
void		ft_chunk_remove(t_chunk *chunk);

/* Functions from lstchunk_utils1.c */

t_lstchunk	*ft_lstchunk_create(t_chunk *chunk);
void		ft_lstchunk_remove(t_lstchunk **lstchunk);
void		ft_lstchunk_clear(t_lstchunk **lstchunk);
void		ft_lstchunk_addback(t_lstchunk **lst_chunk, t_lstchunk *new);
t_chunk		*ft_lstchunk_getchunk(t_lstchunk *lst_chunk, int id);

#endif
