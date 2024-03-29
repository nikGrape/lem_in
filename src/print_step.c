/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:14:12 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 13:40:58 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char *g_colors1[] = {
	"{red}", "{green}", "{yellow}", "{blue}",
	"{magenta}", "{cyan}", "{bold_gray}"
};

int		print_step(t_ant *ant, t_ant **tmp)
{
	int step;

	step = (ant == *tmp) ? 1 : 0;
	ft_printf("%s", (ant == *tmp) ? "\n" : "");
	if (!ant->room->is_start)
		ft_printf("L%s%d{eoc}-%s ", g_colors1[ant->name % 7],\
		ant->name, ant->room->room_name);
	if (!*tmp)
		*tmp = ant;
	if (ant->room->is_end && *tmp == ant)
		*tmp = NULL;
	return (step);
}
