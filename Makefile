# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 13:28:51 by rbulanad          #+#    #+#              #
#    Updated: 2023/05/04 18:09:03 by rbulanad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
SOURCES		= main.c \
			  get_next_line_bonus.c \
			  get_next_line_utils_bonus.c \
			  ft_split.c \
			  ft_strjoin.c \
			  ft_atoi.c \
			  window.c \
			  file_read2.c \
			  graphics.c \
			  draw_algo.c \
			  gradient.c
OBJECTS		= ${SOURCES:.c=.o}
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS} 
	${CC} ${CFLAGS} ${OBJECTS} -lmlx -lm -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
