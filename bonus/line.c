/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:54:59 by Nik               #+#    #+#             */
/*   Updated: 2019/11/10 01:28:21 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	line(t_visual data)
{
	float	step_x;
	float	step_y;
	float	max;

	step_x = data.x2 - data.x1;
	step_y = data.y2 - data.y1;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(data.x1 - data.x2) || (int)(data.y1 - data.y2))
	{
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.y1, data.x1, data.color);
		data.x1 += step_x;
		data.y1 += step_y;
		if (data.x1 > 1600 || data.y1 > 1600 || data.y1 < -800 || data.x1 < -800)
			break ;
	}
}
