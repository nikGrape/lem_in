/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:49:53 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 13:37:09 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "../src/lem_in.h"
# include "minilibx_macos/mlx.h"
# include "math.h"

typedef struct
{
	int			scale;
	int			color;
	int			shift_x;
	int			shift_y;
	char		*finished;
	int			steps;
	void		*mlx_ptr;
	void		*win_ptr;
	t_room		*head;
	t_room		*start;
	t_paths		*paths;
	t_ant		*tmp;
	t_ant		*ant;
	t_queue		*queue;
	int			count;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
}				t_visual;

void			drew_paths(t_visual data);
void			drew_roms(t_visual data);
void			line(t_visual data);
void			restart(t_visual *data);
void			visual_clear(t_visual *data);

int				visual_go(t_visual *data);
t_queue			*create_ants_queue(t_room *start);
void			next_step(t_ant *ant, t_paths *paths);
t_ant			*new_ant(int name, t_room *start);

char			*ft_strattach(char *s1, char *s2, int del);

#endif
