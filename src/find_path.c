/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:45:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/10 01:23:37 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static void		add_path_num(t_room *room, int num)
{
	if (!room->is_end && !room->is_start)
		room->path_num = num;
	else
		room->path_num = 0;
}

static t_links	*new_path(void *data, int num, t_links *back)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->data = data;
	new->next = NULL;
	new->back = back;
	add_path_num(data, num);
	return (new);
}

static t_links	*get_path(t_room *end, t_room *start)
{
	t_links		*path;
	t_links		*tmp;
	static int	path_num;

	path = new_path(end, path_num, NULL);
	tmp = path;
	path_num++;
	while (end != start)
	{
		end = end->parent;
		tmp->next = new_path(end, path_num, tmp);
		tmp = tmp->next;
	}
	return (path);
}

t_links			*find_path(t_room *start)
{
	t_links	*path;
	t_room	*tmp;
	t_links *checked;
	t_queue *queue;

	path = NULL;
	checked = new_link(start);
	queue = q_new(start);
	while ((tmp = (t_room*)q_get(&queue)))
	{
		if (tmp->is_end)
		{
			path = get_path(tmp, start);
			break ;
		}
		add_all(tmp, &queue, checked);
	}
	q_del(&queue);
	clear_links(checked);
	return (path);
}
