/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 22:26:14 by Nik              ###   ########.fr       */
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

t_room		*find_room(t_room *head, char *name)
{
	while (!ft_strequ(head->room_name, name) && head->next)
		head = head->next;
	return (head);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_room *head = read_rooms("text.txt");
	t_room *start = find_start(head);
	print_rooms(head);
	
	t_room *room = find_room(head, argv[1]);

	t_links *path = find_path(room);
	print_path(path);
	// while(1);
}
