/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:12:11 by Nik               #+#    #+#             */
/*   Updated: 2019/11/11 00:32:13 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../queue/queue.h"
# include "../libft/libft.h"

# define FD 0

typedef struct		s_links
{
	void			*data;
	struct s_links	*next;
	struct s_links	*back;
}					t_links;

typedef struct		s_room
{
	char			*room_name;
	int				path_num;
	int				is_start;
	int				is_end;
	int				num_of_ants;
	int				ant_name;
	struct s_room	*next;
	struct s_room	*parent;
	int				x;
	int				y;
	t_links			*links;
}					t_room;

typedef struct		s_paths
{
	t_links			*path;
	int				num;
	int				len;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_ant
{
	int				name;
	t_room			*room;
	t_links			*path;
}					t_ant;

t_room				*read_rooms();
void				read_links(char *line, t_room *head);
t_paths				*get_all_paths(t_room *start);
t_links				*find_path(t_room *start);

int					go(t_room *start, t_paths *paths);
int					print_step(t_ant *ant, t_ant **tmp);

int					is_comment(char *line);
int					get_ants_number();
void				add_ants_to_start(int num, t_room *head);
/*
**			queue with checked rooms
*/
int					is_checked(t_links *link, t_links *checked);
void				checked_add(t_links *link, t_links *checked);

t_links				*new_link(void *data);
t_ant				*new_ant(int name, t_room *start);

t_links				*rev_list(t_links *path);

void				clear(t_paths *paths, t_room *rooms);
void				clear_links(t_links *links);
void				errors(char *msg);
/*
**					-more
*/
void				more(t_paths *paths, t_room *head);
/*
**					bonus -v
*/
void				visual(t_room *head, t_room *start, t_paths *paths);

#endif
