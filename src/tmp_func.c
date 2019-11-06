/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:49:15 by nikgrape          #+#    #+#             */
/*   Updated: 2019/11/06 11:50:38 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(t_room *head, char *name)
{
	while (!ft_strequ(head->room_name, name) && head->next)
		head = head->next;
	return (head);
}

void	print_rooms(t_room *head)
{
	int i;
	t_links *tmp;

	while(head)
	{
		ft_printf("room - %s ant:%d: ants#%d path:%d  ", head->room_name, head->ant_name, head->num_of_ants, head->path_num);
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
		arrow = "-->";
		path = path->next;
	}
	ft_printf("\n");
}


void	rev_print_path(t_links *path)
{
	char *arrow = "";
	
	ft_printf("%s", path ? "\nshortest path:  " : "no path");
	while (path->next)
		path = path->next;
	while (path)
	{
		ft_printf("%s%s", arrow, ((t_room*)path->data)->room_name);
		arrow = "-->";
		path = path->back;
	}
	ft_printf("\n");
}

void	print_all_paths(t_paths *paths)
{
	while (paths)
	{
		print_path(paths->path);
		paths = paths->next;
	}
}
