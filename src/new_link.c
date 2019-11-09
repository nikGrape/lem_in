/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:18:34 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 00:02:17 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links		*new_link(void *data)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->data = data;
	new->next = NULL;
	return (new);
}

t_ant		*new_ant(int name, t_room *start)
{
	t_ant *new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->name = name;
	new->room = start;
	new->path = NULL;
	return (new);
}
