/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:49:15 by nikgrape          #+#    #+#             */
/*   Updated: 2019/11/09 18:38:17 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_rooms(t_room *head)
{
	int		i;
	t_links	*tmp;
	char	*start_end;

	while (head)
	{
		start_end = (head->is_start) ? "{bold_green}" : "";
		start_end = (head->is_end) ? "{red}" : start_end;
		ft_printf("%s   %-6s%s  |  %3d    | %3d    |  ",\
		start_end, head->room_name, "{eoc}",\
		head->num_of_ants, head->path_num);
		tmp = head->links;
		i = 1;
		while (tmp)
		{
			ft_printf("%s%s ", ((t_room*)(tmp->data))->room_name,\
			(tmp->next) ? "," : "");
			i = 0;
			tmp = tmp->next;
		}
		ft_printf("\n");
		head = head->next;
	}
}

void		print_path(t_links *path)
{
	char		*arrow;
	static int	num;

	arrow = "";
	if (!num)
		num = 1;
	ft_printf("{green}\n%d %s", num, path ? "path:  " : "no path");
	while (path)
	{
		ft_printf("%s%s", arrow, ((t_room*)path->data)->room_name);
		arrow = "-->";
		path = path->next;
	}
	ft_printf("{eoc}\n");
	num++;
}

void		print_all_paths(t_paths *paths)
{
	while (paths)
	{
		print_path(paths->path);
		paths = paths->next;
	}
}

void		more(t_paths *paths, t_room *head)
{
	ft_printf("\n------------------------rooms------------------------\n\n");
	ft_printf("room name  |  #ants  |  path  |  links\n");
	print_rooms(head);
	ft_printf("\n------------------------paths------------------------\n");
	print_all_paths(paths);
	ft_printf("\n------------------------steps------------------------\n\n");
}
