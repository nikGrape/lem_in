/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:14:12 by Nik               #+#    #+#             */
/*   Updated: 2019/11/07 21:04:19 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_step(t_ant *ant, t_ant **tmp)
{
	ft_printf("%s", (ant == *tmp) ? "\n" : "");
	if (!ant->room->is_start)
		ft_printf("L%d - %s ", ant->name, ant->room->room_name);
	if (!*tmp)
		*tmp = ant;
	if (ant->room->is_end && *tmp == ant)
		*tmp = NULL;
}
