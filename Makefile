#target: depensencies
#	action

#output: main.o message.o
#	g++ main.o message.o -o ouput //compound the object files to make an executable

#main.o: main.cpp
#	g++ -c main.cpp //compile .cpp file to an objecy file, -c don't create an executable

#message.o: message.cpp message.h
#	g++ -c message.cpp

#clean:
#	rm *.c output

NAME = phonebook

CC = g++
FLAGS = -Wall -Wextra -Werror
FLAGS += -g
FLAGS += -std=c++98
RM = rm -f
SRCS =	main.cpp \
		phonebook.cpp \

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}
#pattern rules contain %
#Define a pattern rule, that compiles every .c file into a .o file
%.o : %.c
	${CC} -c ${FLAGS} $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean