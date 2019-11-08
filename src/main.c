/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 01:18:06 by Nik              ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	// open("text2.txt", O_RDONLY, 0);
	t_room *head = read_rooms();
	t_room *start = find_start(head);
	t_paths *paths = get_all_paths(start);

	if (argc == 2 && ft_strstr(argv[1], "-v"))
		visual(head, start, paths);
	else
		go(start, paths);
	clear(paths, head);
	// while(1);
}
