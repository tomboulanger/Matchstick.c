##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_getnbr.c \

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
