# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:13:02 by luguilla          #+#    #+#              #
#    Updated: 2022/03/10 10:59:04 by luguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c gnl/*.c window/*.c check_map/*.c deplacement/*.c\
		ft_printf/*.c ft_printf/sources/*.c)

OBJS	=	${SRCS:.c=.o}

NAME	=	so_long

CC	=		gcc

CFLAGS	=	-Wall -Wextra -Werror -g

LFLAGS = ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/include 

MLX	= ./minilibx

RM	=		rm -f

.c.o:	so_long
		$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS) $(MLX)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
