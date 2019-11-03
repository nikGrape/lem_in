/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:11:46 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 01:33:27 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(int fd, char *line)
{
	t_room *new;
	char **data;
	
	new = (t_room*)malloc(sizeof(t_room));
	new->is_end = 0;
	new->is_start = 0;
	if (ft_strstr(line, "##start"))
		new->is_start = 1;
	else if (ft_strstr(line, "##end"))
		new->is_end = 1;
	if (new->is_start || new->is_end)
	{
		free(line);
		get_next_line(fd, &line);
	}
	data = ft_strsplit(line, ' ');
	new->ant_name = 0;
	new->num_of_ants = 0;
	new->room_name = ft_strdup(data[0]);
	new->y = ft_atoi(data[1]);
	new->x = ft_atoi(data[2]);
	new->links = NULL;
	new->next = NULL;
	new->parent = NULL;
	ft_arrayfree(data);
	return (new);
}

int		get_number_of_ants(int fd)
{
	int ants;
	char *line;

	get_next_line(fd, &line);
	ants = ft_atoi(line);
	free(line);
	return (ants);
}

void	add_link(t_room *room, t_room *new)
{
	t_links *tmp;

	if (!room->links)
	{
		room->links = (t_links*)malloc(sizeof(t_links));
		room->links->data = new;
		room->links->next = NULL;
		return ;
	}
	tmp = room->links;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_links*)malloc(sizeof(t_links));
	tmp->next->data = new;
	tmp->next->next = NULL;
}

void	make_link(char *name1, char *name2, t_room *head)
{
	t_room *link1;
	t_room *link2;

	link1 = NULL;
	link2 = NULL;
	while ((!link1 || !link2) && head)
	{
		if (ft_strequ(head->room_name, name1))
			link1 = head;
		else if (ft_strequ(head->room_name, name2))
			link2 = head;
		head = head->next;
	}
	add_link(link1, link2);
	add_link(link2, link1);
}

void	get_links(char *line, int fd, t_room *head)
{
	char **data;

	data = ft_strsplit(line, '-');
	make_link(data[0], data[1], head);
	ft_arrayfree(data);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue ;
		}
		data = ft_strsplit(line, '-');
		make_link(data[0], data[1], head);
		ft_arrayfree(data);
		free(line);
	}
}

t_room	*get_rooms(int fd)
{
	t_room	*head;
	t_room	*tmp;
	char	*line;

	get_next_line(fd, &line);
	head = new_room(fd, line);
	tmp = head;
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue ;
		}
		if (ft_strchr(line, '-'))
		{
			get_links(line, fd, head);
			return (head);
		}
		tmp->next = new_room(fd, line);
		tmp = tmp->next;
		free(line);
	}
	return (head);
}

t_room	*get_start(char *file_name)
{
	t_room	*new;
	int		number_of_ants;
	int		fd;

	if ((fd = open(file_name, O_RDONLY, 0)) < 0)
		return (NULL);
	number_of_ants = get_number_of_ants(fd);
	ft_printf("#ants: %d\n", number_of_ants);
	new = get_rooms(fd);
	close(fd);
	return (new);
}