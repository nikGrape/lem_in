/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:49:08 by Nik               #+#    #+#             */
/*   Updated: 2019/11/07 21:57:01 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_room		*global_head;
t_room		*global_start;
t_paths		*global_paths;
void		*mlx_ptr;
void		*win_ptr;

void	set_param()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "lem_in");
}

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	line(float x1, float y1, float x2, float y2)
{
	float	step_x;
	float	step_y;
	float	max;

	step_x = x2 - x1;
	step_y = y2 - y1;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, y1, x1, 0xfc0345);
		x1 += step_x;
		y1 += step_y;
		if (x1 > 800 || y1 > 800 || y1 < 0 || x1 < 0)
			break ;
	}
}

void	drew_roms(t_room *head)
{
	char *room;
	t_links *tmp;

	
	while (head)
	{
		room = ft_strjoin(head->room_name, "[");
		if (!head->is_end)
			room = ft_strjoin_free(room, ft_itoa(head->ant_name), 2);
		else
		{
			room = ft_strjoin_free(room, "#", 1);
			room = ft_strjoin_free(room, ft_itoa(head->num_of_ants), 2);
		}
		room = ft_strjoin_free(room, "]", 1);
		mlx_string_put(mlx_ptr, win_ptr, head->y * 30, head->x * 30, 0xeff542, room);
		tmp = head->links;
		while (tmp)
		{
			line(head->x * 30, head->y * 30, ((t_room*)tmp->data)->x * 30, ((t_room*)tmp->data)->y * 30);
			tmp = tmp->next;
		}
		free(room);
		head = head->next;
	}
}

int		deal_key(int c, void *param)
{
	mlx_clear_window(mlx_ptr, win_ptr);
	static char *end;
	char *tmp;
	tmp = visual_go(global_start, global_paths);
	if (!end)
		end = tmp;
	else
		end = ft_strjoin(end, tmp);
	drew_roms(global_head);
	mlx_string_put(mlx_ptr, win_ptr, 20, 750, 0x4bf542, end);
	return (0);
}

void	visual(t_room *head, t_room *start, t_paths *paths)
{
	global_head = head;
	global_paths = paths;
	global_start = start;
	set_param();
	
	drew_roms(global_head);
	mlx_key_hook(win_ptr, deal_key, NULL);
	mlx_loop(mlx_ptr);
}
