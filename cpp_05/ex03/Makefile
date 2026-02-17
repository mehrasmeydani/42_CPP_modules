																	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehras <mehras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 14:44:18 by codespace         #+#    #+#              #
#    Updated: 2026/01/26 23:16:24 by mehras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp\
			 PresidentialPardonForm.cpp Intern.cpp main.cpp
SRCS		= ${addprefix ${PRE_SRC}, ${SRC}}
PRE_SRC		= srcs/
HEAD		= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp\
			 PresidentialPardonForm.hpp Intern.hpp
HEADS		= ${addprefix ${PRE_HEAD}, ${HEAD}}
PRE_HEAD	= header/
NAME		= TryCatch
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address,leak,undefined -g
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
			${RM} ${NAME} $(PRE_OBJ) *_shrubbery

re:			fclean all
			

.PHONY:		all clean fclean re