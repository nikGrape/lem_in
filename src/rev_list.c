/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:42:44 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 16:17:24 by Nik              ###   ########.fr       */
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

	if (!path)
		return (NULL);
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
