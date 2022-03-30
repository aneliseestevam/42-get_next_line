# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestevam <aestevam@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 20:40:57 by aestevam          #+#    #+#              #
#    Updated: 2022/03/30 14:26:34 by aestevam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = 	main.c \
		get_next_line.c \
		get_next_line_utils.c

BSRCS = main_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c 

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=1 -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

git: 
	git add .
	git commit -m "auto git"
	git push

norm: 
	norminette *.c *.h

clean:
	rm -f ${OBJS}
	rm -f ${BOBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

# bonus: 	${BOBJS}
# 	ar -rcs $(NAME) ${BOBJS}

.PHONY: all, bonus, clean, fclean, re