/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 00:11:53 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 00:20:50 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	restart(t_visual *data)
{
	t_room *end;

	end = data->head;
	while (!end->is_end)
		end = end->next;
	data->start->num_of_ants = end->num_of_ants;
	end->num_of_ants = 0;
	data->count = 0;
	data->steps = 1;
	ft_strclr(data->finished + 14); 
}
