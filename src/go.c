/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 01:40:40 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 00:57:29 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths		*find_free_path(t_paths *paths)
{
	while (paths)
	{
		if (((t_room*)paths->path->next->data)->ant_name == 0)
			return (paths);
		paths = paths->next;
	}
	return (NULL);
}

t_links		*choose_path(t_paths *paths, int num_of_ants_in_start)
{
	t_paths *path;

	if (!(path = find_free_path(paths)))
		return (NULL);
	if (path->len - paths->len >= num_of_ants_in_start)
		return (NULL);
	return (path->path);
}

void		next_step(t_ant *ant, t_paths *paths)
{
	if (!ant->path)
		ant->path = choose_path(paths, ant->room->num_of_ants);
	if (ant->path)
	{
		ant->room->num_of_ants--;
		ant->room->ant_name = 0;
		ant->path = ant->path->next;
		ant->room = ((t_room*)(ant->path->data));
		ant->room->ant_name = ant->name;
		ant->room->num_of_ants++;
	}
}

t_queue		*create_ants_queue(t_room *start)
{
	t_queue	*queue;
	int		name;

	name = 1;
	queue = q_new(new_ant(name++, start));
	while (name <= start->num_of_ants)
		q_add(&queue, new_ant(name++, start));
	return (queue);
}

int			go(t_room *start, t_paths *paths)
{
	t_queue	*queue;
	t_ant	*ant;
	t_ant	*tmp;
	int		steps;

	tmp = NULL;
	steps = 1;
	queue = create_ants_queue(start);
	while ((ant = (t_ant*)q_get(&queue)))
	{
		next_step(ant, paths);
		if (!ant->room->is_end)
			q_add(&queue, ant);
		steps += print_step(ant, &tmp);
		if (ant->room->is_end)
			free(ant);
	}
	ft_printf("\n");
	return (steps);
}
