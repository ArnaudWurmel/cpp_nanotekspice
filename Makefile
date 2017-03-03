##
## Makefile for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Fri Jan 27 19:13:05 2017 Arnaud WURMEL
## Last update Fri Mar  3 13:54:49 2017 Arnaud WURMEL
##

CC=		g++

SRC_PATH=	srcs

COMPONENT=	Components

MAIN_SRCS=	$(SRC_PATH)/main.cpp \

SRCS=		Parser/Parser.cpp \
		$(SRC_PATH)/NanoTekSpice.cpp \
		$(SRC_PATH)/Helper.cpp \
		Errors/Errors.cpp \
		$(COMPONENT)/c2716.cpp \
		$(COMPONENT)/c4001.cpp \
		$(COMPONENT)/c4008.cpp \
		$(COMPONENT)/c4011.cpp \
		$(COMPONENT)/c4013.cpp \
		$(COMPONENT)/c4017.cpp \
		$(COMPONENT)/c4030.cpp \
		$(COMPONENT)/c4040.cpp \
		$(COMPONENT)/c4069.cpp \
		$(COMPONENT)/c4071.cpp \
		$(COMPONENT)/c4081.cpp \
		$(COMPONENT)/c4094.cpp \
		$(COMPONENT)/c4514.cpp \
		$(COMPONENT)/c4801.cpp \
		$(COMPONENT)/cInput.cpp \
		$(COMPONENT)/cOutput.cpp \
		$(COMPONENT)/cClock.cpp \
		$(COMPONENT)/Component.cpp \
		$(COMPONENT)/ComponentFactory.cpp \
		$(COMPONENT)/cFalse.cpp \
		$(COMPONENT)/cTrue.cpp

OBJS=		$(SRCS:.cpp=.o)

MAIN_OBJS=	$(MAIN_SRCS:.c=.o)

CXXFLAGS+=	-I ./Interface -I ./include -I ./Parser -Wall -Wextra -std=c++11 -I ./Errors -I ./$(COMPONENT) -g

NAME=		nanotekspice

$(NAME):	$(OBJS) $(MAIN_OBJS)
		ar rc libnanotekspice.a $(OBJS)
		ranlib libnanotekspice.a
		$(CC) -o $(NAME) $(MAIN_OBJS) -lnanotekspice -L . $(CXXFLAGS)

all:		$(NAME)

clean:
		rm -rf $(SRC_PATH)/main.o
		rm -rf $(OBJS)

fclean:		clean
		rm -rf libnanotekspice.a
		rm -rf $(NAME)

re:		fclean all
