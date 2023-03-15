# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 15:55:59 by artvan-d          #+#    #+#              #
#    Updated: 2023/03/15 14:54:22 by artvan-d         ###   ########.fr        #
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
			Sources/pipex_utils.c \
			Sources/split_path.c \
			Sources/utils.c \
			
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
