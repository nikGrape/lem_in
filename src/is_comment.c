/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:23:18 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 16:22:02 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
	{
		ft_printf("%s\n", line);
		free(line);
		return (1);
	}
	else if (ft_strlen(line) < 2)
		errors("Empty line occured!\n");
	return (0);
}
