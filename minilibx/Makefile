# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 15:41:04 by bbenaali          #+#    #+#              #
#    Updated: 2025/02/02 09:08:45 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c

OBJC = ${SRC:.c=.o}

NAME = fractal


CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = libmlx.a

all: ${NAME}

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}:${OBJC}
	${CC} ${FLAGS} $(OBJC) ${LIB} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJC}
fclean: clean
	${RM} ${NAME}

re: fclean all