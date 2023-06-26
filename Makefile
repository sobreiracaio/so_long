# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 08:04:49 by wcorrea-          #+#    #+#              #
#    Updated: 2023/06/25 17:46:36 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = so_long

SRC = src/main.c utils/utils.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C

MLX_PATH = lib/mlx

MLX	= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(OUT): ${OBJS}
		
		${MAKE} ${MLX_PATH}
		${CC} ${OBJS} ${MLX} -o ${OUT}

all:	${OUT}

clean:
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re