##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	format_line.c	\
			my_arraylen.c	\
			get_buffer.c	\
			free_array.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy.a

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) ..
	cp include/lib.h ../../include/libmy.h

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) ../../include/lib.h

re:     fclean all

.PHONY: all clean fclean re
