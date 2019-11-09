/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:34:59 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 23:58:40 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*q_get(t_queue **queue)
{
	void	*data;
	t_queue	*tmp;

	if (!*queue)
		return (NULL);
	data = (*queue)->data;
	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
	tmp = NULL;
	return (data);
}
