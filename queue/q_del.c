/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:19:08 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 23:44:25 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	q_del(t_queue **queue)
{
	t_queue *tmp;
	t_queue *lnext;

	if (queue != NULL)
	{
		tmp = *queue;
		lnext = *queue;
		while (tmp != NULL)
		{
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*queue = NULL;
	}
}
