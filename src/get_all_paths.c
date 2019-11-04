/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:54:55 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 01:22:46 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_path(t_links *path, t_links *new)
{

		while (path->next)
			path = path->next;
		path->next = new_link(new);

}

t_links			*get_all_paths(t_room *start)
{
	t_links *paths;
	t_links *tmp;

	paths = new_link(find_path(start));
	while ((tmp = find_path(start)))
	{
		add_path(paths, tmp);
	}
	return (paths);
}