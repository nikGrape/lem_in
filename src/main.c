/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 18:15:08 by Nik              ###   ########.fr       */
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

	head = read_rooms();
	start = find_start(head);
	if (!(paths = get_all_paths(start)))
		errors("No possible solution!\n");
	if (argc == 2 && ft_strequ(argv[1], "-more"))
		more(paths, head);
	if (argc == 2 && ft_strequ(argv[1], "-v"))
		visual(head, start, paths);
	else
		go(start, paths);
	clear(paths, head);
}
