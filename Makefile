##
## EPITECH PROJECT, 2022
## ZAPPY
## File description:
## makefile
##

all: ai server gui

ai:
	-make -C ai
	-mv ./ai/zappy_ai ./ || true

gui:
	-make -C gui
	-mv ./gui/zappy_gui ./ || true

server:
	-make -C server
	-mv ./server/zappy_server ./ || true

clean:
	make clean -C ai
	make clean -C gui
	make clean -C server

fclean:
	rm zappy_ai || true
	rm zappy_gui || true
	rm zappy_server || true
	make fclean -C ai || true
	make fclean -C gui || true
	make fclean -C server || true

re: fclean all

.PHONY: all re clean fclean ai server gui