/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 01:40:40 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 15:00:25 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_ant(t_ant *ant)
{
	free(ant);//does not ready
}

t_ant	*new_ant(int name, t_room *start)
{
	t_ant *new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->name = name;
	new->room = start;
	new->path = NULL;
	return (new);
}

t_links	*choose_path(t_paths *paths)
{
	t_links *path;
	
	path = NULL;
	while (paths)
	{
		if (((t_room*)paths->path->next->data)->ant_name == 0)
			return (paths->path);
		paths = paths->next;
	}
	return (NULL);
}

void	next_step(t_ant *ant, t_paths *paths)
{
	if (!ant->path)
		ant->path = choose_path(paths);
	if (ant->path)
	{
		ant->room->ant_name = 0;
		ant->path = ant->path->next;
		ant->room = ((t_room*)(ant->path->data));
		ant->room->ant_name = ant->name;
	}
}

void	go(t_room *start, t_paths *paths)
{
	t_queue	*queue;
	t_ant	*ant;
	int		name;

	name = 1;
	queue = q_new(new_ant(name++, start));
	while (name <= start->num_of_ants)
		q_add(&queue, new_ant(name++, start));
	while ((ant = (t_ant*)q_get(&queue)))
	{
		next_step(ant, paths);
		if (ant->room->is_end)
			del_ant(ant);
		else
			q_add(&queue, ant);
		print_step(ant, start->num_of_ants);
	}
}