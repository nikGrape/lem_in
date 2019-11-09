/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 00:10:08 by vinograd         ###   ########.fr       */
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
	t_room	*head;
	t_room	*start;
	t_paths	*paths;

	open("tests/test_big_superposition.txt", O_RDONLY, 0);
	head = read_rooms();
	start = find_start(head);
	paths = get_all_paths(start);
	if (argc == 2 && ft_strstr(argv[1], "-v"))
		visual(head, start, paths);
	else
		go(start, paths);
	clear(paths, head);
}
