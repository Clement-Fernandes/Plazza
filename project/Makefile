##
## EPITECH PROJECT, 2022
## B-CCP-400-PAR-4-1-theplazza-clement.fernandes
## File description:
## Makefile
##

MAIN_SOURCE		=	src/main/main.cpp				\

SOURCE			=	src/library/strToWordArr.cpp	\
					src/library/displayFile.cpp		\
					src/library/readFile.cpp		\
					src/main/plazza.cpp				\
					src/Reception/Reception.cpp		\
					src/Reception/setOrder.cpp		\
					src/Kitchen.cpp					\
					src/modules/Order.cpp			\


MAIN_OBJ		=	$(MAIN_SOURCE:.cpp=.o)

OBJ				=	$(SOURCE:.cpp=.o)

NAME			=	plazza

CXX				?=	g++

COPY			?=	cp -f
COPY_FILE		?=	$(COPY)
COPY_DIR		?=	$(COPY) -r

DELETE			?=	rm -f
DELETE_FILE		?=	$(DELETE)
DELETE_DIR		?=	$(DELETE) -r

INCLUDE_DIRS	+=	-I src/Error/ -I include/ -I src/modules/ -I src/Reception/ -I src/

CXXFLAGS		+=	-W -Wall -Wextra
CXXFLAGS		+=	$(INCLUDE_DIRS)
CXXFLAGS		+=	-std=c++2a

all:	$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJ)
	$(CXX) -o $(NAME) $(MAIN_OBJ) $(OBJ)

clean:
	$(DELETE_FILE) $(MAIN_OBJ)
	$(DELETE_FILE) $(OBJ)

fclean:	clean
	$(DELETE_FILE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
