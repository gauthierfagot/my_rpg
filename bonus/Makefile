##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for colision generator
##

SRC	=	$(addprefix colision_script/,\
			main.c	\
			format_line.c	\
			get_buffer.c	\
			generate_colision.c	\
		)	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./colision_script/include

NAME	=	colision_generator

CC	?=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
