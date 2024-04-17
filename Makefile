##
## EPITECH PROJECT, 2023
## $MAKEFILE
## File description:
## Makefile for sokoban
##

INCLUDE	=	-I./include/

SRC	=	src/main.c	\
		src/player.c	\
		src/check_map.c	\
		src/count_chars.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/information.c	\
		src/sokoban.c	\
		src/check_win.c	\
		src/my_strcpy.c	\
		src/check_original.c	\
		src/check_loss.c	\

CFLAGS	+=	-g -W

OBJ 	= 	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE) -lncurses

clean:
	rm -f $(OBJ)
	rm -f *.out
	rm -f *.log
	rm -f *.gcda
	rm -rf *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
