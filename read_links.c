/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:22:26 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 21:24:14 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_link(t_room *room, t_room *new)
{
	t_links *tmp;

	if (!room->links)
		room->links = new_link(new);
	else
	{
		tmp = room->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link(new);
	}
}

static void	make_link(char *name1, char *name2, t_room *head)
{
	t_room *link1;
	t_room *link2;

	link1 = NULL;
	link2 = NULL;
	while ((!link1 || !link2) && head)
	{
		if (ft_strequ(head->room_name, name1))
			link1 = head;
		else if (ft_strequ(head->room_name, name2))
			link2 = head;
		head = head->next;
	}
	add_link(link1, link2);
	add_link(link2, link1);
}

void		get_links(char *line, int fd, t_room *head)
{
	char **data;

	data = ft_strsplit(line, '-');
	make_link(data[0], data[1], head);
	ft_arrayfree(data);
	while (get_next_line(fd, &line))
	{
		if (is_comment(line))
			continue ;
		data = ft_strsplit(line, '-');
		make_link(data[0], data[1], head);
		ft_arrayfree(data);
		free(line);
	}
}