/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:49:53 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 00:14:36 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VISUAL_H
# define VISUAL_H

# include "../src/lem_in.h"
# include "minilibx_macos/mlx.h"

t_queue		*create_ants_queue(t_room *start);
void		next_step(t_ant *ant, t_paths *paths);
t_ant		*new_ant(int name, t_room *start);
char		*visual_go(t_room *start, t_paths *paths);

#endif
