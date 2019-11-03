/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:14:12 by Nik               #+#    #+#             */
/*   Updated: 2019/11/02 23:23:34 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_room *head)
{
	int i;
	while(head)
	{
		ft_printf("name - %s\n", head->room_name);
		i = 1;
		while (head->links)
		{
			ft_printf("%s--->",((t_room*)(head->links->data))->room_name);
			head->links = head->links->next;
		}
		ft_printf("null\n");
		head = head->next;
	}
}