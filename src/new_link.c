/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:18:34 by Nik               #+#    #+#             */
/*   Updated: 2019/11/03 21:43:09 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links *new_link(void *data)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->data = data;
	new->next = NULL;
	return (new);
}