/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:17:09 by Nik               #+#    #+#             */
/*   Updated: 2019/11/08 23:59:35 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct		s_queue
{
	void			*data;
	struct s_queue	*next;
}					t_queue;

t_queue				*q_new(void *data);
void				*q_get(t_queue **queue);
void				q_add(t_queue **queue, void *data);
void				q_del(t_queue **queue);

#endif
