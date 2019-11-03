/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:34:59 by Nik               #+#    #+#             */
/*   Updated: 2019/11/02 23:44:19 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*q_get(t_queue **queue)
{
	void	*data;
	t_queue	*tmp;
	
	if (!*queue)
		return(NULL);
	data = (*queue)->data;
	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
	tmp = NULL;
	return (data);
}