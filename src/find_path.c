/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:45:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 00:47:23 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_checked(t_links *link, t_links *checked)
{
	while (checked)
	{
		if (checked->data == link->data)
			return (1);
		checked = checked->next;
	}
	return (0);
}

static void		checked_add(t_links *link, t_links *checked)
{
	if (!checked)
	{
		checked = new_link(link->data);
		return ;
	}
	while (checked->next)
		checked = checked->next;
	checked->next = new_link(link->data);
}

static void		add_all(t_room *tmp, t_queue **queue, t_links *checked)
{
	t_links *link;

	link = tmp->links;
	while (link)
	{
		if (!is_checked(link, checked))
		{
			if ((((t_room*)link->data)->path_num) == 0)
			{
				q_add(queue, link->data);
				((t_room*)link->data)->parent = tmp;
			}
			checked_add(link, checked);
		}
		link = link->next;
	}
}

void	add_path_num(t_room *room, int num)
{
	if (!room->is_end && !room->is_start)
		room->path_num = num;
}

static t_links *get_path(t_room *end, t_room *start)
{
	t_links *path;
	t_links *tmp;
	static int path_num;

	path = new_link(end);
	add_path_num(path->data, path_num);
	tmp = path;
	path_num++;
	while (end != start)
	{
		end = end->parent;
		tmp->next = new_link(end);
		add_path_num(tmp->next->data, path_num);
		tmp = tmp->next;
	}
	return (path);
}

t_links	*find_path(t_room *start)
{
	t_room	*tmp;
	t_links *checked;
	t_queue *queue;
	
	checked = new_link(start);
	queue = q_new(start);
	while ((tmp = (t_room*)q_get(&queue)))
	{
		if (tmp->is_end)
			return (get_path(tmp, start));
		add_all(tmp, &queue, checked);
	}
	return (NULL);
}