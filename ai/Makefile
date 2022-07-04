##
## EPITECH PROJECT, 2022
## TEK2
## File description:
## Makefile
##

NAME	=	zappy_ai
SRC		= 	main.py

SRC_TEST	=

all:	$(NAME)

$(NAME):
	cp main.py $(NAME)
	chmod +x $(NAME)

tests_run:

debug:

clean:
	rm -f $(NAME)

clean_test:
	rm -f *.gcda *.gcno unit_tests

fclean: 	clean clean_test
	find \( -name "*~" -o -name *"#*" -a -name "*#" \) -delete
	find \( -name "vgcore.*" \) -delete

re:	fclean all

.PHONY : 	all clean fclean re