/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:34:22 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 15:42:31 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ants_number(void)
{
	int		ants;
	char	*line;

	get_next_line(FD, &line);
	ants = ft_atoi(line);
	if (ants < 1 || ft_strchr(line, ' '))
		ants = -1;
	free(line);
	return (ants);
}

void	add_ants_to_start(int num, t_room *head)
{
	while (head)
	{
		if (head->is_start)
		{
			head->num_of_ants = num;
			break ;
		}
		head = head->next;
	}
}
