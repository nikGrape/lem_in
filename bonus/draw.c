/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:52:42 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 13:39:14 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			g_colors[] = {
	0xe9f0ea, 0xe30e31, 0x42ed13, 0xe1e807, 0x1b0cc4, 0x8d0cc4, 0x13ebe7
};

void	draw_links(t_visual data)
{
	t_links	*tmp;

	tmp = data.head->links;
	data.x1 = data.head->x * data.scale + data.shift_x;
	data.y1 = data.head->y * data.scale + data.shift_y;
	data.color = g_colors[0];
	while (tmp)
	{
		data.x2 = ((t_room*)tmp->data)->x * data.scale + data.shift_x;
		data.y2 = ((t_room*)tmp->data)->y * data.scale + data.shift_y;
		line(data);
		tmp = tmp->next;
	}
}

char	*make_room_info(t_visual data)
{
	char	*room;

	room = ft_strjoin(data.head->room_name, "[");
	if (!data.head->is_end && !data.head->is_start)
		room = ft_strjoin_free(room, ft_itoa(data.head->ant_name), 2);
	else
	{
		room = ft_strjoin_free(room, "#", 1);
		room = ft_strjoin_free(room, ft_itoa(data.head->num_of_ants), 2);
	}
	room = ft_strjoin_free(room, "]", 1);
	return (room);
}

void	drew_roms(t_visual data)
{
	char	*room_info;

	while (data.head)
	{
		data.x1 = data.head->x * data.scale + data.shift_x;
		data.y1 = data.head->y * data.scale + data.shift_y;
		room_info = make_room_info(data);
		data.color = (data.head->is_end) ? g_colors[1] : g_colors[3];
		data.color = (data.head->is_start) ? g_colors[2] : data.color;
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.y1,\
		data.x1, data.color, room_info);
		draw_links(data);
		free(room_info);
		data.head = data.head->next;
	}
}

void	drew_paths(t_visual data)
{
	t_room	*room1;
	t_room	*room2;
	t_links	*path;

	while (data.paths)
	{
		path = data.paths->path;
		while (path->next)
		{
			room1 = (t_room*)path->data;
			room2 = (t_room*)path->next->data;
			data.x1 = room1->x * data.scale + data.shift_x;
			data.y1 = room1->y * data.scale + data.shift_y;
			data.x2 = room2->x * data.scale + data.shift_x;
			data.y2 = room2->y * data.scale + data.shift_y;
			data.color = g_colors[data.paths->num % 7];
			line(data);
			path = path->next;
		}
		data.paths = data.paths->next;
	}
}
