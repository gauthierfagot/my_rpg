##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile for my paint
##

SRC	=	$(addprefix src/,\
			main.c	\
			sprite_size.c	\
			$(addprefix map_parsing/,\
				get_char_map.c	\
				get_map.c	\
			)	\
			$(addprefix init/,\
				init_floor_sprite.c	\
				init_texture.c	\
			)	\
		)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LIB	=	./lib/libmy.a

CPPFLAGS	=	-iquote./include/

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

LDLIBS	=	$(CSFML) -lmy -lm

LDFLAGS	=	-L./lib

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

make_lib:
	make -C ./lib/my

$(NAME):	make_lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

colision:
	make re -C ./bonus/
	./bonus/colision_generator

clean:
	$(RM) $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./lib/my

debug: CFLAGS += -ggdb3
debug: re

asan:	CC	=	clang -fsanitize=address
asan:	re

re:	fclean	all

.PHONY: all clean fclean debug re
