/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:26:43 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 23:58:48 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*q_new(void *data)
{
	t_queue *new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->data = data;
	new->next = NULL;
	return (new);
}
