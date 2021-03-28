##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=			src/main.c			\
				src/utils.c			\
				src/map.c 			\
				src/victory.c		\
				src/error.c 		\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g3

LDFLAGS	=	-lmy -L ./lib/my/

NAME	=	matchstick

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re: fclean all