/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:12:11 by Nik               #+#    #+#             */
/*   Updated: 2019/11/04 00:59:50 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../queue/queue.h"
#include "../libft/libft.h"

typedef struct	l_links
{
	void *data;
	struct l_links *next;
}				t_links;


typedef struct	l_room
{
	char			*room_name;
	int				path_num;
	int				is_start;
	int				is_end;
	int				num_of_ants;
	int				ant_name;
	struct l_room *next;
	struct l_room *parent;
	int x;
	int y;
	struct l_links *links;  // linked list of links
}				t_room;

t_room		*read_rooms(char *file_name);
t_links		*find_path(t_room *start);
void		get_links(char *line, int fd, t_room *head);
t_links		*get_all_paths(t_room *start);

t_links 	*new_link(void *data);
int			is_comment(char *line);
int			get_ants_number(int fd);
void		add_ants_to_start(int num, t_room *head);

	/*	temporary functions	 */
void		print_rooms(t_room *head);
void		print_path(t_links *path);
void		print_all_paths(t_links *paths);

#endif