# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 13:28:51 by rbulanad          #+#    #+#              #
#    Updated: 2023/03/24 12:52:35 by rbulanad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
SOURCES		= main.c \
			  window.c \
			  ft_split.c \
			  get_next_line2/get_next_line_utils.c \
			  get_next_line2/get_next_line.c
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
