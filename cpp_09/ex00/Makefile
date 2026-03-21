# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megardes <megardes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 14:44:18 by codespace         #+#    #+#              #
#    Updated: 2026/03/21 16:40:47 by megardes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.cpp BitcoinExchange.cpp
SRCS		= ${addprefix ${PRE_SRC}, ${SRC}}
PRE_SRC		= srcs/
HEAD		= BitcoinExchange.hpp
HEADS		= ${addprefix ${PRE_HEAD}, ${HEAD}}
PRE_HEAD	= header/
NAME		= btc
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address,leak,undefined -g
OBJ			= ${SRC:.cpp=.o}
PRE_OBJ		= obj/
OBJS		= ${addprefix ${PRE_OBJ}, ${OBJ}}
RM			= rm -fr
CXX			= c++
MAKEFLAGS	+= --no-print-directory

all:		${NAME}

$(PRE_OBJ)%.o:$(PRE_SRC)%.cpp $(HEADS)
			mkdir -p $(PRE_OBJ)
			${CXX} ${CXXFLAGS} -I ${PRE_HEAD} -o $@ -c $< 

${NAME}:	${OBJS}
			${CXX} ${CXXFLAGS} -I ${PRE_HEAD} ${OBJS} -o ${NAME}

clean: 
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME} $(PRE_OBJ)

re:			fclean all
			

.PHONY:		all clean fclean re