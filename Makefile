# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 00:20:53 by Nik               #+#    #+#              #
#    Updated: 2019/11/07 18:20:25 by Nik              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc src/*.c libft/libft.a queue/*.c

bonus:
	gcc src/*.c libft/libft.a queue/*.c bonus/*.c bonus/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit