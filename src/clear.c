/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:31:30 by nikgrape          #+#    #+#             */
/*   Updated: 2019/11/07 00:44:14 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_links(t_links *links)
{
	t_links *tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(links);
	}
}

void	clear_paths(t_paths *paths)
{
	t_paths *tmp;

	while (paths)
	{
		clear_links(paths->path);
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
}

void	clear_rooms(t_room *rooms)
{
	t_room *tmp;

	while (rooms)
	{
		ft_strdel(&rooms->room_name);
		clear_links(rooms->links);
		tmp = rooms;
		rooms = rooms->next;
		free(tmp);
	}
	
}

void	clear(t_paths *paths, t_room *rooms)
{
	clear_rooms(rooms);
	clear_paths(paths);
}