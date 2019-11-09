/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checked_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:05:15 by vinograd          #+#    #+#             */
/*   Updated: 2019/11/09 00:09:19 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_checked(t_links *link, t_links *checked)
{
	while (checked)
	{
		if (checked->data == link->data)
			return (1);
		checked = checked->next;
	}
	return (0);
}

void	checked_add(t_links *link, t_links *checked)
{
	while (checked->next)
		checked = checked->next;
	checked->next = new_link(link->data);
}
