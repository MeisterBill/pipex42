# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 15:55:59 by artvan-d          #+#    #+#              #
#    Updated: 2023/03/20 15:48:00 by artvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

RM = rm -rf
CC = gcc -g
FLAGS = -Wall -Wextra -Werror

INC = \
			pipex.h \

INCS = $(addprefix -I, $(INC))
			
SRCS = \
			Sources/free.c \
			Sources/main.c \
			Sources/process.c \
			Sources/path.c \
			Sources/string_op.c \
			
OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : $(OBJS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
		${RM} ${OBJS}

fclean : clean 
		${RM} ${NAME}

re : fclean all

%.o: %.c
		${CC} ${FLAGS} -o $@ -c $<
