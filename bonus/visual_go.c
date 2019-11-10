/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:59:47 by Nik               #+#    #+#             */
/*   Updated: 2019/11/10 01:45:30 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		check_step(t_visual *data)
{
	if (!data->tmp)
		data->tmp = data->ant;
	if (data->ant->room->is_end && data->tmp == data->ant)
		data->tmp = NULL;
	if (data->ant->room->is_end)
	{
		data->finished = ft_strattach(data->finished, ft_itoa(data->ant->name), 3);
		data->finished = ft_stradd(data->finished, ' ');
		free(data->ant);
	}
	return (data->tmp == q_check_next(data->queue));
}

int		visual_go(t_visual *data)
{
	static int		count;
	int				ret;

	data->tmp = NULL;
	ret = (data->queue) ? 1 : 0;
	if (!count)
		data->queue = create_ants_queue(data->start);
	while ((data->ant = (t_ant*)q_get(&data->queue)))
	{
		next_step(data->ant, data->paths);
		count++;
		if (!data->ant->room->is_end)
			q_add(&data->queue, data->ant);
		if (check_step(data))
			break;
	}
	return (ret);
}
