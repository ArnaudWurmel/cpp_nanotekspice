##
## Makefile for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Fri Jan 27 19:13:05 2017 Arnaud WURMEL
## Last update Fri Jan 27 19:15:15 2017 Arnaud WURMEL
##

CC=		g++

SRC_PATH=	srcs

SRCS=		$(SRC_PATH)/main.cpp

OBJS=		$(SRCS:.cpp=.o)

CXXFLAGS+=	-I ./header -Wall -Wextra -std=c++03

NAME=		nanotekspice

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
