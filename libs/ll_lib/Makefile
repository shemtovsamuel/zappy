##
## EPITECH PROJECT, 2022
## Jour 10
## File description:
## Makefile
##

SRC	=	add_list.c	\
		del_list.c	\
		get_list.c	\
		information_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libll.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ ar -rsc $(NAME) $(OBJ)
	@ mv $(NAME) ../

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f ../$(NAME)

re: fclean all