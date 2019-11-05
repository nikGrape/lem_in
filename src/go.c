/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 01:40:40 by Nik               #+#    #+#             */
/*   Updated: 2019/11/05 00:38:27 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_ant(t_ant *ant)
{
	free(ant);
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

t_paths	*find_free_path(t_paths *paths) 
{
	while (paths)
	{
		if (((t_room*)paths->path->next->data)->ant_name == 0)
			return (paths);
		paths = paths->next;
	}
	return (NULL);
}

t_links *choose_path(t_paths *paths, int num_of_ants_in_start)
{
	t_paths *path;
	
	if (!(path = find_free_path(paths)))
		return (NULL);
	if (path->len - paths->len > num_of_ants_in_start)
		return (NULL);
	return (path->path);
}

void	next_step(t_ant *ant, t_paths *paths)
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

void	go(t_room *start, t_paths *paths)
{
	t_queue	*queue;
	t_ant	*ant;
	int		name;
	int i = 0;
	int		total_ants = start->num_of_ants;

	name = 1;
	queue = q_new(new_ant(name++, start));
	while (name <= start->num_of_ants)
		q_add(&queue, new_ant(name++, start));
	t_ant *tmp = NULL;
	while ((ant = (t_ant*)q_get(&queue)))
	{
		next_step(ant, paths);
		if (!ant->room->is_end)
			q_add(&queue, ant);
		print_step(ant, (tmp == ant) ? 1 : 0);
		if (!tmp)
			tmp = ant;
		if (ant->room->is_end && tmp == ant)
		{
			del_ant(ant);
			tmp = NULL;
		}
	}
	ft_printf("\n");
}