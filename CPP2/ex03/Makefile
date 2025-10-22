# Variables
.SILENT:

NAME		= BSP

SRC			= main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ			= ${SRC:.cpp=.o}

# Compiler
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Rules
all: 		${NAME}
			echo "Project up to date"

${NAME}:	${OBJ}
			${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}
			echo "Build done"

clean:
			rm -f ${OBJ}
			echo "clean done"

fclean:		clean
			rm -f ${NAME}
			echo "fclean done"

re:			fclean all

.PHONY:		all clean fclean re
