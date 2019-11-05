/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:11:46 by Nik               #+#    #+#             */
/*   Updated: 2019/11/05 00:10:34 by Nik              ###   ########.fr       */
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
	if (new->is_start || new->is_end)
		free(line);
	else
		return (0);
	return (1);
}

static t_room	*new_room(int fd, char *line)
{
	t_room *new;
	char **data;
	
	new = (t_room*)malloc(sizeof(t_room));
	set_zero(new);
	if (start_end(line, new))
		get_next_line(fd, &line);
	data = ft_strsplit(line, ' ');
	new->room_name = ft_strdup(data[0]);
	new->y = ft_atoi(data[1]);
	new->x = ft_atoi(data[2]);
	ft_arrayfree(data);
	return (new);
}

static t_room	*get_rooms(int fd)
{
	t_room	*head;
	t_room	*tmp;
	char	*line;

	get_next_line(fd, &line);
	head = new_room(fd, line);
	tmp = head;
	while (get_next_line(fd, &line))
	{
		if (is_comment(line))
			continue ;
		if (ft_strchr(line, '-'))
			break ;
		tmp->next = new_room(fd, line);
		tmp = tmp->next;
		free(line);
	}
	get_links(line, fd, head);
	return (head);
}

t_room	*read_rooms(char *file_name)
{
	t_room	*new;
	int		number_of_ants;
	int		fd;

	if ((fd = open(file_name, O_RDONLY, 0)) < 0)
		return (NULL);
	number_of_ants = get_ants_number(fd);
	new = get_rooms(fd);
	add_ants_to_start(number_of_ants, new);
	close(fd);
	return (new);
}