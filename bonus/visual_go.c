/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:59:47 by Nik               #+#    #+#             */
/*   Updated: 2019/11/07 22:24:16 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char	*visual_go(t_room *start, t_paths *paths)
{
	static t_queue	*queue;
	static t_ant	*ant;
	t_ant	*tmp = NULL;
	char	*end = "";

	if (!queue)
		queue = create_ants_queue(start);
	if (ant)
	{
		if (ant->room->is_end)
			end = ft_strjoin(end, ft_itoa(ant->name));
		next_step(ant, paths);
		if (!ant->room->is_end)
			q_add(&queue, ant);
	}
	while ((ant = (t_ant*)q_get(&queue)))
	{
		if (ant == tmp)
			return (end);
		next_step(ant, paths);
		if (!ant->room->is_end)
			q_add(&queue, ant);
		print_step(ant, &tmp);
		if (ant->room->is_end)
		{
			end = ft_strjoin_free(end, ft_itoa(ant->name), 2);
			end = ft_strjoin_free(end, " ", 1);
			free(ant);
		}
	}
	return (end);
}
