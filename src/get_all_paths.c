/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:54:55 by Nik               #+#    #+#             */
/*   Updated: 2019/11/06 11:14:25 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			path_len(t_links *path)
{
	int i;

	i = 0;
	if (!path)
		return (__INT_MAX__);
	while ((path = path->next))
		i++;
	return (i);
}

t_paths *new_paths_enlem(t_links *data, int num)
{
	t_paths *new;

	new = (t_paths*)malloc(sizeof(t_paths));
	new->path = data;
	new->num = num;
	new->len = path_len(data);
	new->next = NULL;
	return (new);
}

static void		add_path(t_paths *path, t_links *new, int num)
{
	while (path->next)
		path = path->next;
	path->next = new_paths_enlem(new, num);
}

t_paths			*get_all_paths(t_room *start)
{
	t_paths *paths;
	t_links *tmp;
	int		num;

	num = 1;
	paths = new_paths_enlem(rev_list(find_path(start)), num++);
	while ((tmp = find_path(start)))
	{
		add_path(paths, rev_list(tmp), num++);
	}
	return (paths);
}
