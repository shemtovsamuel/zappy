##
## EPITECH PROJECT, 2022
## my_teams
## File description:
## makefile
##

MAIN	= 	src/main.c

SRC     =	src/server/command.c							\
			src/server/init_server.c						\
			src/server/message.c							\
			src/server/new_client.c							\
			src/server/server_loop.c						\
			src/server/write.c								\
			src/server/read.c								\
			src/game/do_cmd.c								\
			src/parser/parser.c								\
			src/parser/arg/arg_c.c							\
			src/parser/arg/arg_f.c							\
			src/parser/arg/arg_n.c							\
			src/parser/arg/arg_p.c							\
			src/parser/arg/arg_x.c							\
			src/parser/arg/arg_y.c							\
			src/game/unset/gui_msg.c	\
			src/game/gui/gui.c			\
			src/game/gui/cmd/send_tile.c	\
			src/game/gui/cmd/msz.c	\
			src/game/gui/cmd/bct.c	\
			src/game/gui/cmd/mct.c	\
			src/game/gui/cmd/tna.c	\
			src/game/gui/cmd/ppo.c	\
			src/game/gui/cmd/plv.c	\
			src/game/gui/cmd/pin.c	\
			src/game/gui/cmd/sgt.c	\
			src/game/gui/cmd/sst.c	\
			src/game/loop/game_loop.c						\
			src/game/loop/core_functions.c						\
			src/game/loop/event/forward.c		\
			src/game/loop/event/left.c			\
			src/game/loop/event/right.c			\
			src/game/loop/event/look.c			\
			src/game/loop/event/inventory.c		\
			src/game/loop/event/broadcast.c		\
			src/game/loop/event/slots.c			\
			src/game/loop/event/fork.c			\
			src/game/loop/event/eject.c			\
			src/game/loop/event/take.c			\
			src/game/loop/event/set.c			\
			src/game/loop/event/incantation.c	\
			src/game/unset/unset.c							\
			src/game/player/player.c						\
			src/game/player/c_forward.c						\
			src/game/player/c_forward_tools_1.c				\
			src/game/player/c_forward_tools_2.c				\
			src/game/player/c_right.c						\
			src/game/player/c_left.c						\
			src/game/player/c_look.c						\
			src/game/player/c_look_tools.c					\
			src/game/player/c_inventory.c					\
			src/game/player/c_broadcast.c					\
			src/game/player/c_broadcast_tools.c				\
			src/game/player/c_connect_nbr.c					\
			src/game/player/c_fork.c						\
			src/game/player/c_eject.c						\
			src/game/player/c_eject_tools.c					\
			src/game/player/c_take.c						\
			src/game/player/c_take_tools.c					\
			src/game/player/c_set.c							\
			src/game/player/c_set_tools.c					\
			src/game/player/c_incantation.c					\
			src/game/player/c_incantation_tools.c			\
			src/comp/is_nbr.c								\
			src/comp/quick_message.c						\
			src/comp/create_message.c						\
			src/comp/create_empty_struct.c					\
			src/comp/int_to_str.c							\
			src/comp/get_argument.c							\
			src/comp/get_team_from_nb.c						\
			src/parser/set_team_player_limit.c				\
			src/parser/map/create_map.c						\
			src/comp/str_to_words_array.c	\

TEST	=

NAME    =	zappy_server

OBJ		=	$(SRC:.c=.o)

FLAGS 	=	-I ./include/ -L ../libs/ -lll

all:	$(NAME)

$(NAME):	$(OBJ)
	-make -C ../libs/ll_lib
	@ gcc -o $(NAME) $(OBJ) $(MAIN) $(FLAGS)

%.o:	%.c
	@ echo -e "\033[1;32m [GCC]: Compiling" $< "\033[0m"
	- gcc -o $@ -c $< -I./include/


clean:
	-make -C ../libs/ll_lib clean
	rm -f $(OBJ)

fclean:	clean
	-make -C ../libs/ll_lib fclean
	rm $(NAME) || true

re: 	fclean all

tests_clean: clean
	-rm *.gcda
	-rm *.gcno
	-rm unit_tests

tests_run:
	gcc -o unit_tests $(SRC) $(TEST) $(FLAGS) --coverage -lcriterion
	./unit_tests

.PHONY: all re clean fclean tests_run tests_clean
