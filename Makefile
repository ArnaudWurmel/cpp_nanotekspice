##
## Makefile for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Fri Jan 27 19:13:05 2017 Arnaud WURMEL
## Last update Wed Mar  1 18:23:48 2017 Arnaud WURMEL
##

CC=		g++

SRC_PATH=	srcs

COMPONENT=	Components

SRCS=		$(SRC_PATH)/main.cpp \
		Parser/Parser.cpp \
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
		$(COMPONENT)/ComponentFactory.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS+=	-I ./Interface -I ./include -I ./Parser -Wall -Wextra -std=c++11 -I ./Errors -I ./$(COMPONENT) -g

NAME=		nanotekspice

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
