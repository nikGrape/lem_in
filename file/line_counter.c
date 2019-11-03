/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:23:05 by Nik               #+#    #+#             */
/*   Updated: 2019/11/02 18:30:31 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int		line_conuter(char *file_name)
{
	int lines;
	int fd;
	char c;
	
	lines = 1;
	if ((fd = open(file_name, O_RDONLY, 0)) < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}