# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehras <mehras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 14:44:18 by codespace         #+#    #+#              #
#    Updated: 2025/12/19 05:14:45 by mehras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
SRCS		= ${addprefix ${PRE_SRC}, ${SRC}}
PRE_SRC		= srcs/
HEAD		= HumanA.hpp HumanB.hpp Weapon.hpp
PRE_HEAD	= header/
HEADS		= ${addprefix ${PRE_HEAD}, ${HEAD}}
NAME		= zombie
CFLAGS		= -Wall -Wextra -Werror -std=c++98
OBJ			= ${SRC:.cpp=.o}
PRE_OBJ		= obj/
OBJS		= ${addprefix ${PRE_OBJ}, ${OBJ}}
RM			= rm -fr
CC			= c++
MAKEFLAGS	+= --no-print-directory

all:		${NAME}

$(PRE_OBJ)%.o:$(PRE_SRC)%.cpp	$(HEADS)
			mkdir -p $(PRE_OBJ)
			${CC} ${CFLAGS} -I ${PRE_HEAD} -o $@ -c $< 

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I ${PRE_HEAD} ${OBJS} -o ${NAME}

clean: 
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME} $(PRE_OBJ)

re:			fclean all
			

.PHONY:		all clean fclean re