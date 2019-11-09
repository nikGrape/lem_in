/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:42:44 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 15:50:50 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_links(t_links **next, t_links **back)
{
	t_links *tmp;

	tmp = *next;
	*next = *back;
	*back = tmp;
}

t_links		*rev_list(t_links *path)
{
	t_links *rev;

	while (path->next)
		path = path->next;
	rev = path;
	while (path)
	{
		swap_links(&path->next, &path->back);
		path = path->next;
	}
	return (rev);
}
