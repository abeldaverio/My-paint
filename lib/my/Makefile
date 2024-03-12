##
## EPITECH PROJECT, 2023
## makefile miniprintf
## File description:
## Makefile for miniprintd
##

SRC	=	my_putstr_error.c	\
		str_to_separators.c	\
		my_strcmp.c	\
		free_array.c	\
		my_arraylen.c	\
		my_strconcat.c	\
		my_strcpy.c	\
		my_strdup.c	\
		int_to_str.c	\
		str_to_int.c	\
		my_arraydup.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp header.h ../../include/libmy.h

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clear fclean re
