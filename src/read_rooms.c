/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:11:46 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 17:23:46 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_zero(t_room *new)
{
	new->is_end = 0;
	new->is_start = 0;
	new->ant_name = 0;
	new->num_of_ants = 0;
	new->links = NULL;
	new->next = NULL;
	new->parent = NULL;
}

static int		start_end(char *line, t_room *new)
{
	if (ft_strstr(line, "##start"))
		new->is_start = 1;
	else if (ft_strstr(line, "##end"))
		new->is_end = 1;
	else
		return (0);
	return (1);
}

static t_room	*new_room(char *line)
{
	t_room	*new;
	char	**data;
	char	*new_line;

	new_line = line;
	new = (t_room*)malloc(sizeof(t_room));
	set_zero(new);
	if (start_end(line, new))
		get_next_line(FD, &new_line);
	data = ft_strsplit(new_line, ' ');
	new->room_name = ft_strdup(data[0]);
	new->y = ft_atoi(data[1]);
	new->x = ft_atoi(data[2]);
	ft_arrayfree(data);
	if (new_line != line)
		free(new_line);
	return (new);
}

static t_room	*get_rooms(void)
{
	t_room	*head;
	t_room	*tmp;
	char	*line;

	get_next_line(FD, &line);
	head = new_room(line);
	free(line);
	tmp = head;
	while (get_next_line(FD, &line))
	{
		if (is_comment(line))
			continue ;
		if (ft_strchr(line, '-'))
			break ;
		tmp->next = new_room(line);
		tmp = tmp->next;
		free(line);
	}
	free(line);
	read_links(line, head);
	return (head);
}

t_room			*read_rooms(void)
{
	t_room	*new;
	int		number_of_ants;

	number_of_ants = get_ants_number();
	new = get_rooms();
	add_ants_to_start(number_of_ants, new);
	return (new);
}
