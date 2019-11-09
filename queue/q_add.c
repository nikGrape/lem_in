/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:30:45 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 23:58:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	q_add(t_queue **queue, void *data)
{
	t_queue *new;

	new = *queue;
	if (!new)
	{
		*queue = q_new(data);
		return ;
	}
	while (new->next)
		new = new->next;
	new->next = (t_queue*)malloc(sizeof(t_queue));
	new = new->next;
	new->data = data;
	new->next = NULL;
}
