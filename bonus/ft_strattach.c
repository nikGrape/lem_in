/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strattach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:18:20 by Nik               #+#    #+#             */
/*   Updated: 2019/11/09 21:24:04 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	indx 0 - nothing will be freed;
**	indx 1 - s1 will be freed;
**	indx 2 - s2 will be freed;
**	indx 3 - evrething will be freed;
*/

#include "visual.h"

char	*ft_strattach(char *s1, char *s2, int del)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = (s2) ? ft_strlen(s2) : 0;
	if (!(new = ft_strnew(len1 + len2)))
		return (NULL);
	ft_strcat(new, s1 ? s1 : "");
	ft_strcat(new, s2 ? s2 : "");
	if ((del == 1 || del == 3) && s1)
		free(s1);
	if ((del == 2 || del == 3) && s2)
		free(s2);
	return (new);
}
