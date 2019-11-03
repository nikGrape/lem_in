/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:45:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 01:54:43 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links *new_link(void *data)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->data = data;
	new->next = NULL;
	return (new);
}

int		is_checked(t_links *link, t_links *checked)
{
	while (checked)
	{
		if (checked->data == link->data)
			return (1);
		checked = checked->next;
	}
	return (0);
}

void	checked_add(t_links *link, t_links *checked)
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

void	add_all(t_room *tmp, t_queue **queue, t_links *checked)
{
	t_links *link;

	link = tmp->links;
	while (link)
	{
		if (!is_checked(link, checked))
		{
			q_add(queue, link->data);
			checked_add(link, checked);
			((t_room*)link->data)->parent = tmp;
		}
		link = link->next;
	}
}

t_links *get_path(t_room *tmp)
{
	t_links *path;

	path = new_link(tmp);
	while (tmp->parent->is_start == 0)
	{
		tmp = tmp->parent;
		path->next = new_link(tmp);
		path = path->next;
	}
	return (path);
}

t_links	*find_path(t_room *start)
{
	t_room	*tmp;
	t_links *checked;
	t_links *path;
	t_queue *queue;
	
	checked = new_link(start);
	queue = q_new(start);
	while ((tmp = (t_room*)q_get(&queue)))
	{
		if (tmp->is_end)
			break;
		else
			add_all(tmp, &queue, checked);
	}
	while (tmp->is_start == 0)
	{
		ft_printf("%s<--", tmp->room_name);
		tmp = tmp->parent;
	}
	ft_printf("%s", tmp->room_name);
	ft_printf("\n\n");
	// path = get_path(tmp);
	return (path);
}