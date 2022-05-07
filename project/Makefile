##
## EPITECH PROJECT, 2022
## B-CCP-400-PAR-4-1-theplazza-clement.fernandes
## File description:
## Makefile
##

MAIN_SOURCE		=	src/main/main.cpp					\

SOURCE			=	src/library/strToWordArr.cpp		\
					src/library/displayFile.cpp			\
					src/library/readFile.cpp			\
					src/library/printColored.cpp		\
					src/main/plazza.cpp					\
					src/Reception/Reception.cpp			\
					src/Reception/setOrder.cpp			\
					src/Reception/orderDistribution.cpp	\
					src/Kitchen/Kitchen.cpp				\
					src/Fridge/Fridge.cpp				\
					src/Order/Order.cpp					\
					src/Cook/Cook.cpp					\
					src/Process/Process.cpp				\
					src/IPC/IPC.cpp						\
					src/Clock/Clock.cpp					\
					src/ThreadPool/ThreadPool.cpp		\

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

INCLUDE_DIRS	+=	-I src/Error/ -I include/ -I src/Order/ -I src/Reception/
INCLUDE_DIRS	+=	-I src/Kitchen/ -I src/Cook/ -I src/Fridge/ -I src/Classes/
INCLUDE_DIRS	+=	-I src/Clock/ -I src/IPC/ -I src/Process/ -I src/ThreadPool/

CXXFLAGS		+=	-W -Wall -Wextra
CXXFLAGS		+=	$(INCLUDE_DIRS)
CXXFLAGS		+=	-std=c++2a

LDFLAGS			+=	-lpthread

all:	$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJ)
	$(CXX) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 20s\n" $(NAME) | tr ' ' '.'

clean:
	$(DELETE_FILE) $(MAIN_OBJ)
	$(DELETE_FILE) $(OBJ)

fclean:	clean
	$(DELETE_FILE) $(NAME)
	@printf "[\033[0;35mdeleted\033[0m] % 18s\n" $(NAME) | tr ' ' '.'

re:	fclean all

.PHONY: all clean fclean re
