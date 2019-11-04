/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:14:12 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 01:13:39 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_room *head)
{
	int i;
	t_links *tmp;

	while(head)
	{
		ft_printf("room - %s ants:%d: path:%d  ", head->room_name, head->num_of_ants, head->path_num);
		tmp = head->links;
		i = 1;
		while (tmp)
		{
			ft_printf("%s%s-->", (i ? "links: " : ""), ((t_room*)(tmp->data))->room_name);
			i = 0;
			tmp = tmp->next;
		}
		ft_printf("null\n");
		head = head->next;
	}
}

void	print_path(t_links *path)
{
	char *arrow = "";
	
	ft_printf("%s", path ? "\nshortest path:  " : "no path");
	while (path)
	{
		ft_printf("%s%s", arrow, ((t_room*)path->data)->room_name);
		arrow = "<--";
		path = path->next;
	}
	ft_printf("\n");
}

void	print_all_paths(t_links *paths)
{
	while (paths)
	{
		print_path(paths->data);
		paths = paths->next;
	}
}