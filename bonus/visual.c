/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:49:08 by Nik               #+#    #+#             */
/*   Updated: 2019/11/10 20:31:44 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_visual *init_data(t_room *head, t_room *start, t_paths *paths)
{
	t_visual *data;

	data = (t_visual*)malloc(sizeof(t_visual));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "lem_in");
	data->head = head;
	data->start = start;
	data->paths = paths;
	data->finished = ft_strdup("ants finised: ");
	data->scale = 30;
	data->shift_x = 20;
	data->shift_y = 20;
	data->steps = 1;
	return (data);
}

void	set_data(int c, t_visual *data)
{
	if (c == 24)
		data->scale += 5;
	else if (c == 27 && data->scale > 5)
		data->scale -= 5;
	else if (c == 126)
		data->shift_x -= 20;
	else if (c == 125)
		data->shift_x += 20;
	else if (c == 123)
		data->shift_y -= 20;
	else if (c == 124)
		data->shift_y += 20;
	else if (c == 49)
		data->steps += visual_go(data);
}

int		deal_key(int c, t_visual *data)
{
	if (c == 49 || c == 24 || c == 27 || (c >= 123 && c <= 126))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set_data(c, data);
		drew_roms(*data);
		drew_paths(*data);
		if (data->finished)
			mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 750, 0x4bf542, data->finished);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 700, 0x4bf542, ft_strattach("steps: ", ft_itoa(data->steps), 2));
	}
	else if (c == 53)
		visual_clear(data);
	return (0);
}

void	visual(t_room *head, t_room *start, t_paths *paths)
{
	t_visual *data;
	
	data = init_data(head, start, paths);
	drew_roms(*data);
	drew_paths(*data);
	mlx_hook(data->win_ptr, 2, 5, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
