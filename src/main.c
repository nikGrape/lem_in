/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 01:19:10 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_start(t_room *head)
{
	while (head)
	{
		if (head->is_start)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int			steps_count(t_links *path)
{
	int i;

	i = 0;
	if (!path)
		return (__INT_MAX__);
	while ((path = path->next))
		i++;
	return (i);
}

t_room		*find_room(t_room *head, char *name)
{
	while (!ft_strequ(head->room_name, name) && head->next)
		head = head->next;
	return (head);
}



int			main(int argc, char **argv)
{
	t_room *head = read_rooms("text.txt");
	t_room *start = find_start(head);
	t_links *paths = get_all_paths(start);
	
	print_all_paths(paths);
	
	print_rooms(head);
	// while(1);
}
