/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:17:09 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 01:43:24 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

#include <stdlib.h>

typedef struct	s_queue
{
	void *parent;
	void *data;
	struct s_queue *next;
}				t_queue;

t_queue	*q_new(void *data);
void	*q_get(t_queue **queue);
void	q_add(t_queue **queue, void *data);

#endif