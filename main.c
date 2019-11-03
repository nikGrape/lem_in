/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:50:38 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 01:53:51 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room *find_start(t_room *head)
{
	while (head)
	{
		if (head->is_start)
			return (head);
		head = head->next;
	}
	return (NULL);
}


int main()
{
	t_room *head = get_start("text.txt");
	t_room *start = find_start(head);
	// print_rooms(head);
	
	t_links *path = find_path(start);
	
	// while (path)
	// {
	// 	ft_printf("%s-->", ((t_room*)path->data)->room_name);
	// 	path = path->next;
	// }

	

	
}
