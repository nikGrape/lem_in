/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:12:11 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 16:11:39 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../queue/queue.h"
# include "../libft/libft.h"

# define FD 3

typedef struct		l_links
{
	void			*data;
	struct l_links	*next;
	struct l_links	*back;
}					t_links;


typedef struct		l_room
{
	char			*room_name;
	int				path_num;
	int				is_start;
	int				is_end;
	int				num_of_ants;
	int				ant_name;
	struct l_room	*next;
	struct l_room	*parent;
	int				x;
	int				y;
	struct l_links	*links;
}					t_room;

typedef struct		l_paths
{
	t_links 		*path;
	int				num;
	int				len;
	struct l_paths	*next;
}					t_paths;

typedef struct		l_ant
{
	int				name;
	t_room			*room;
	t_links			*path;
}					t_ant;

t_room				*read_rooms();
void				read_links(char *line, t_room *head);
t_paths				*get_all_paths(t_room *start);
t_links				*find_path(t_room *start);

void				go(t_room *start, t_paths *paths);
void				print_step(t_ant *ant, t_ant **tmp);

int					is_comment(char *line);
int					get_ants_number();
void				add_ants_to_start(int num, t_room *head);
t_links				*new_link(void *data);
t_links				*rev_list(t_links *path);

void				clear(t_paths *paths, t_room *rooms);

/*
**			temporary functions
*/
void				print_rooms(t_room *head);
void				print_path(t_links *path);
void				print_all_paths(t_paths *paths);
t_room				*find_room(t_room *head, char *name);

/*
**					bonus
*/
void				visual(t_room *head, t_room *start, t_paths *paths);

#endif
