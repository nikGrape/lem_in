/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:32:44 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 21:34:02 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	visual_clear(t_visual *data)
{
	free(data->finished);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear(data->paths, data->head);
	free(data);
	exit(1);
}
