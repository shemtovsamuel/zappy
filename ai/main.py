#!/usr/bin/env python3
# from os import close

# import sys, socket
# from sys import argv
# import random
# import re

# class Food():
#     def __init__(self, name, quantity):
#         self.name = name
#         self.quantity = quantity

# class Inventory():
#     def __init__(self):
#         self.food = []
#         self.food.append(Food(" food", 0))
#         self.food.append(Food(" linemate", 0))
#         self.food.append(Food(" deraumere", 0))
#         self.food.append(Food(" sibur", 0))
#         self.food.append(Food(" mendiane", 0))
#         self.food.append(Food(" phiras", 0))
#         self.food.append(Food(" thystame", 0))

# class Commands():
#     FORWARD = "Forward\n"
#     RIGHT = "Right\n"
#     LEFT = "Left\n"
#     LOOK = "Look\n"
#     INVENTORY = "Inventory\n"
#     BROADCAST_TEXT = "Broadcast text\n"
#     CONNECT_NBR = "Connect_nbr\n"
#     FORK = "Fork\n"
#     EJECT = "Eject\n"
#     TAKE_FOOD = "Take food\n"
#     TAKE_LIMENATE = "Take linemate\n"
#     TAKE_DERAUMERE = "Take deraumere\n"
#     TAKE_SIBUR = "Take sibur\n"
#     TAKE_MENDIANE = "Take mendiane\n"
#     TAKE_PHIRAS = "Take phiras\n"
#     TAKE_THYSTAME = "Take thystame\n"
#     SET_LIMENATE = "Set linemate\n"
#     SET_DERAUMERE = "Set deraumere\n"
#     SET_SIBUR = "Set sibur\n"
#     SET_MENDIANE = "Set mendiane\n"
#     SET_PHIRAS = "Set phiras\n"
#     SET_THYSTAME = "Set thystame\n"
#     SET_OBJECT = "Set object\n"
#     INCANTATION = "Incantation\n"

# arg = ["port", "name", "localhost"]
# server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# inventory = Inventory()
# map = ["x", "y"]
# isLevel1 = True

# def print_help():
#     print("\tport\tis the port number")
#     print("\tname\tis the name of the team")
#     print("\tmachine\tis the name of the machine; localhost by default")

# def print_error(message):
# 	print(message)
# 	exit(84)

# def check_error():
#     check_p = 0
#     check_n = 0
#     try:
#         for i in range (1, len(sys.argv), 2):
#             if sys.argv[i] == "-p":
#                 arg[0] = int(sys.argv[i + 1])
#                 check_p += 1
#             if sys.argv[i] == "-n":
#                 check_n += 1
#                 arg[1] = str(sys.argv[i + 1])
#             if sys.argv[i] == "-h":
#                 arg[2] = str(sys.argv[i + 1])
#         if check_p != 1 or check_n != 1:
#             exit(84)
#     except:
#         print_help()
#         exit(84)

# def print_client(message):
#     print("-->" + message)

# def print_server(message):
#     print("<--" + message.replace('\n', '', -1))

# def convert_byte_to_str(message):
#     return message.decode()

# def convert_str_to_byte(message):
#     return bytes(message, "utf-8")

# def connect_to_server():
#     try:
#         server_socket.connect((arg[2], arg[0]))
#     except:
#         print_error("Invalid port or/and machine name or/and the server is closed")

# def disconnect_from_server():
#     server_socket.close()

# def send_to_server(message):
#     server_socket.send(convert_str_to_byte(message + '\n'))

# def receive_from_server():
#     return convert_byte_to_str(server_socket.recv(1024))

# def get_clientnum_and_map_size(info):
# 	tmp = info.split('\n', -1)
# 	if tmp[0] == "ko":
# 		print_error("the " + arg[1] + " team is not in game, check the name or find an other team")
# 	client_num = int(tmp[0])
# 	map[0] = int(tmp[1].split(' ', -1)[0])
# 	map[1] = int(tmp[1].split(' ', -1)[1])
# 	return client_num

# def start_connection():
# 	connect_to_server()                 							# CONNECTE le client avec le serveur
# 	print_server(receive_from_server())								# RECOIE le "WELCOME" du serveur et l'imprime
# 	send_to_server(arg[1])              							# ENVOIE le nom de la team au serveur
# 	print_client(arg[1])											# TMP juste pour TEST
# 	client_num = get_clientnum_and_map_size(receive_from_server())	# RECOIE le nombre de client qui peuvent se connecter avec le nom de la team donnée ET les dimensions du monde en X Y
# 	print_server(str(client_num))
# 	print_server(str(map[0]) + " " + str(map[1]))
# 	if client_num < 1:
# 		print_error("Cannot connect because the number of clients that can still be accepted by the server for the" + arg[1] + "team was zero")

# def nb_sep(str, c):
#     nb_commas = 0
#     for i in range(len(str)):
#         if str[i] == c:
#             nb_commas += 1
#     return nb_commas

# def parse_look(look_str):
#     look_array = []
#     temp = look_str.split(',')
#     for i in range (len(temp)):            
#         nb_spaces = nb_sep(temp[i], ' ')
#         word = temp[i].split()
#         look_array.append(word)
#     del look_array[0][0]
#     look_array[len(look_array) - 1].pop()
#     return look_array

# def updateInventory(inventory_str):
#     print(inventory_str)
#     re.findall('\d+', inventory_str)
#     for i in range (7):
#         inventory.food[i].quantity = int(re.findall('\d+', inventory_str)[i])

# def look():
#     look_str = ""
#     surrondings = []
#     send_to_server(Commands.LOOK)
#     print_client(Commands.LOOK)
#     look_str = receive_from_server()
#     surrondings = parse_look(look_str)
#     for i in range(len(surrondings)):
#         print(surrondings[i])
#     return surrondings

# def checkTile(tile, item):
#     for i in range(len(tile)):
#         if tile[i] == item:
#             return True
#     return False

# def connect_nbr():
#     send_to_server(Commands.CONNECT_NBR)
#     print(receive_from_server())

# def eat():
#     send_to_server(Commands.TAKE_FOOD)
#     print(receive_from_server())

# def move_frwd():
#     send_to_server(Commands.FORWARD)
#     print(receive_from_server())

# def move_left():
#     send_to_server(Commands.LEFT)
#     print(receive_from_server())

# def move_right():
#     send_to_server(Commands.RIGHT)
#     print(receive_from_server())

# def take_linemate():
#     send_to_server(Commands.TAKE_LIMENATE)
#     print(receive_from_server())

# def take_deraumere():
#     send_to_server(Commands.TAKE_DERAUMERE)
#     print(receive_from_server())

# def take_sibur():
#     send_to_server(Commands.TAKE_SIBUR)
#     print(receive_from_server())

# def take_mendiane():
#     send_to_server(Commands.TAKE_MENDIANE)
#     print(receive_from_server())

# def take_phiras():
#     send_to_server(Commands.TAKE_PHIRAS)
#     print(receive_from_server())

# def take_thystame():
#     send_to_server(Commands.TAKE_THYSTAME)
#     print(receive_from_server())

# def set_linemate():
#     send_to_server(Commands.SET_LIMENATE)
#     print(receive_from_server())

# def set_deraumere():
#     send_to_server(Commands.SET_DERAUMERE)
#     print(receive_from_server())

# def set_sibur():
#     send_to_server(Commands.SET_SIBUR)
#     print(receive_from_server())

# def set_mendiane():
#     send_to_server(Commands.SET_MENDIANE)
#     print(receive_from_server())

# def set_phiras():
#     send_to_server(Commands.SET_PHIRAS)
#     print(receive_from_server())

# def set_thystame():
#     send_to_server(Commands.SET_THYSTAME)
#     print(receive_from_server())

# def canEvolve():
#     evolve = False
#     global isLevel1
#     if isLevel1 == True and inventory.food[1].quantity >= 1:
#         evolve = True
#     return evolve

# def Evolve():
#     send_to_server(Commands.INCANTATION)
#     print(receive_from_server())
#     print(receive_from_server())

# def drop_item(i):
#     if i == 1:
#         set_linemate()
#     if i == 2:
#         set_deraumere()
#     if i == 3:
#         set_sibur()
#     if i == 4:
#         set_mendiane()
#     if i == 5:
#         set_phiras()
#     if i == 6:
#         set_thystame()

# def go_to_rsc(tile):
#     if tile == 1:
#         print("tile 1")
#         move_frwd()
#         move_left()
#         move_frwd()
#     if tile == 2:
#         print("tile 2")
#         move_frwd()
#     if tile == 3:
#         print("tile 3")
#         move_frwd()
#         move_right()
#         move_frwd()
#     if tile == 4:
#         print("tile 4")
#         move_frwd()
#         move_frwd()
#         move_left()
#         move_frwd()
#         move_frwd()
#     if tile == 5:
#         print("tile 5")
#         move_frwd()
#         move_frwd()
#         move_left()
#         move_frwd()
#     if tile == 6:
#         print("tile 6")
#         move_frwd()
#         move_frwd()
#     if tile == 7:
#         print("tile 7")
#         move_frwd()
#         move_frwd()
#         move_right()
#     if tile == 8:
#         print("tile 8")
#         move_frwd()
#         move_frwd()
#         move_right()
#         move_frwd()
#         move_frwd()

# def checkRscOnTile(tile):
#     for i in range(len(tile)):
#         if 'linemate' in tile[i]:
#             return False
#         if 'deraumere' in tile[i]:
#             return False
#         if 'sibur' in tile[i]:
#             return False
#         if 'mendiane' in tile[i]:
#             return False
#         if 'phiras' in tile[i]:
#             return False
#         if 'thystame' in tile[i]:
#             return False
#     return True

# def chooseOption(surrondings):
#     direction = random.randint(0,2)
#     global isLevel1
#     if canEvolve() == True and checkRscOnTile(surrondings[0]) == True:
#         print("start incantation")
#         drop_item(1)
#         Evolve()
#         isLevel1 = False
#     else:
#         for i in range(1, 6):
#             if inventory.food[i].quantity > 8:
#                 drop_item(i)
#         if inventory.food[0].quantity < 15 and checkTile(surrondings[0], "food") == True:
#             eat()
#         for i in range(len(surrondings)):
#             if 'linemate' in surrondings[i]:
#                 print("pick up linemate")
#                 go_to_rsc(i)
#                 take_linemate()
#                 break
#             elif 'deraumere' in surrondings[i]:
#                 print("pick up deraumere")
#                 go_to_rsc(i)
#                 take_deraumere()
#                 break
#             elif 'sibur' in surrondings[i]:
#                 print("pick up sibur")
#                 go_to_rsc(i)
#                 take_sibur()
#                 break
#             elif 'mendiane' in surrondings[i]:
#                 print("pick up mendiane")
#                 go_to_rsc(i)
#                 take_mendiane()
#                 break
#             elif 'phiras' in surrondings[i]:
#                 print("pick up phiras")
#                 go_to_rsc(i)
#                 take_phiras()
#                 break
#             elif 'thystame' in surrondings[i]:
#                 print("pick up thystame")
#                 go_to_rsc(i)
#                 take_thystame()
#                 break
#         if direction == 0:
#             print("move right")
#             move_right()
#         elif direction == 1:
#             print("move left")
#             move_left()
#         else:
#             print("move fwd")
#             move_frwd()

# def checkInventory():
#     inventory_str = ""
#     send_to_server(Commands.INVENTORY)
#     print_client(Commands.INVENTORY)
#     inventory_str = receive_from_server()
#     updateInventory(inventory_str)

# def Start_IA():
#     surrondings = []
#     print("Number of team unused slots left")
#     connect_nbr()
#     while 1:
#         checkInventory()
#         surrondings = look()
#         chooseOption(surrondings)

# def main():
# 	if (len(sys.argv) == 2 and argv[1] == "-h"):
# 		print_help()
# 	elif (len(sys.argv) == 5 or len(sys.argv) == 7):
# 		check_error()
# 		start_connection()
# 		Start_IA()
# 		disconnect_from_server()									# DECONECTE le client du serveur
# 	else:
# 		print_help()
# 		exit(84)
# 	exit(0)

# if __name__ == "__main__":
#     main() 


#!/usr/bin/env python3
import sys, socket, re
from sys import argv

arg = ["port", "name", "localhost"]															#port, team_name, machine_name
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
map = ["x", "y"]
level = [1]																		#actual_level, suffisant_ressources?, player_recuqired_get? 0 = False, 1 = True
inventory = [0, 0, 0, 0, 0, 0, 0]
inv = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
alive = 1

def print_help():
	print("USAGE: ./zappy_ai -p port -n name -m machine")
	print("\tport\tis the port number")
	print("\tname\tis the name of the team")
	print("\tmachine\tis the name of the machine; localhost by default")

def print_error(message):
	print(message)
	exit(84)

def check_error():
	check_p = 0
	check_n = 0
	try:
		for i in range (1, len(sys.argv), 2):
			if sys.argv[i] == "-p":
				arg[0] = int(sys.argv[i + 1])
				check_p += 1
			if sys.argv[i] == "-n":
				check_n += 1
				arg[1] = str(sys.argv[i + 1])
			if sys.argv[i] == "-m":
				arg[2] = str(sys.argv[i + 1])
		if check_p != 1 or check_n != 1:
			exit(84)
	except:
		print_help()
		exit(84)

def print_client(message):
	print("<-- " + message)

def print_server(message):
	print("--> " + message.replace('\n', '', -1))

def convert_byte_to_str(message):
	return message.decode()

def convert_str_to_byte(message):
	return bytes(message, "utf-8")

def connect_to_server():
	try:
		server_socket.connect((arg[2], arg[0]))
	except:
		print_error("Invalid port or/and machine name or/and the server is closed")

def disconnect_from_server():
	server_socket.close()

def send_to_server(message):
	print_client(message)
	server_socket.send(convert_str_to_byte(message + '\n'))

def receive_from_server():
	return convert_byte_to_str(server_socket.recv(2048))

def get_clientnum_and_map_size(info):
	tmp = info.split('\n', -1)
	if tmp[0] == "ko":
		print_error("the " + arg[1] + " team is not in game, check the name or find an other team")
	client_num = int(tmp[0])
	map[0] = int(tmp[1].split(' ', -1)[0])
	map[1] = int(tmp[1].split(' ', -1)[1])
	return client_num
	
def start_connection():
	connect_to_server()                 							# CONNECTE le client avec le serveur
	check_reception(receive_from_server())							# RECOIE le "WELCOME" du serveur et l'imprime
	send_to_server(arg[1])											# ENVOIE le nom de la team au serveur
	client_num = get_clientnum_and_map_size(receive_from_server())	# RECOIE le nombre de client qui peuvent se connecter avec le nom de la team donnée ET les dimensions du monde en X Y
	print_server(str(client_num))
	print_server(str(map[0]) + " " + str(map[1]))
	if client_num < 1:
		print_error("Cannot connect because the number of clients that can still be accepted by the server for the" + arg[1] + "team was zero")

#################################################### DEBUT DU JEU ###############################################################################

def update_inventory(info):
	tmp = info.replace("[ ", "", -1).replace(" ]\n", "", -1).split(", ", -1)
	x = 0
	for i in tmp:
		inventory[x] = int(i.split(" ")[1])
		x += 1

def print_death():
	print("You are dead, not big suprise!\n" + "you finish at level " + str(level[0]))
	disconnect_from_server()
	exit(0)

def change_level(message):
	level[0] = int(message.split(": ", -1)[1])
	IA()

def pass_level():
	send_to_server("Incantation")
	print_server(receive_from_server())
	message = receive_from_server()
	print_server(message)
	if message.find("Current level: ") != -1: change_level(message)
	return 1

def pass_level_2(view):
	check = 0
	for a in re.finditer("linemate", view[0]): check += 1
	for a in range(1, check) :
		send_to_server("Take " + "linemate")
		check_reception(receive_from_server())
	for idx in range(2, 7):
		for a in re.finditer(inv[idx], view[0]):
			send_to_server("Take " + inv[idx])
			check_reception(receive_from_server())
	return pass_level()

def check_nb_player(nb_recquired):
	nb_player = 0
	send_to_server("Look")
	message = receive_from_server()
	check_level_reception(message)
	print_server(message)
	if message.find("[ player") != -1:
		for a in re.finditer("player", message.split(",")[0]): nb_player += 1
	if nb_player == nb_recquired: return 1
	return 0

def check_level_reception(message):
	if message.find("dead\n") != -1: print_death()

def pick_useless_item(idx, view):
	for a in re.finditer(inv[idx], view[0]):
		send_to_server("Take " + inv[idx])
		print_server(receive_from_server())

def set_needed_item(actual, required, idx):
	for a in range(actual, required):
		send_to_server("Set " + inv[idx])
		print_server(receive_from_server())

def take_too_many_item(required, view, idx):
	actual = 0
	for a in re.finditer(inv[idx], view[0]): actual += 1
	for a in range(required, actual):
		send_to_server("Take " + inv[idx])
		print_server(receive_from_server())
	set_needed_item(actual, required, idx)

def pass_level_3(view):
	# send_to_server("Fork")
	# print_server(receive_from_server())
	for idx in range(1, 4):
		take_too_many_item(1, view, idx)
	for idx in range(4, 7):
		pick_useless_item(idx, view)
	while check_nb_player(2) != 1:
		send_to_server("Broadcast wait level up:3.")
		check_level_reception(receive_from_server())
	send_to_server("Broadcast go level_up:3.")
	check_level_reception(receive_from_server())
	return pass_level()

def pass_level_4(view):
	take_too_many_item(2, view, 1)
	take_too_many_item(1, view, 3)
	take_too_many_item(2, view, 5)
	for idx in range(2, 8, 2):
		pick_useless_item(idx, view)
	while check_nb_player(2) != 1:
		send_to_server("Broadcast wait level up:4.")
		check_level_reception(receive_from_server())
	send_to_server("Broadcast go level_up:4 ")
	check_level_reception(receive_from_server())
	return pass_level()

def pass_level_5(view):
	take_too_many_item(1, view, 1)
	take_too_many_item(1, view, 2)
	take_too_many_item(2, view, 3)
	take_too_many_item(1, view, 5)
	pick_useless_item(4, view)
	pick_useless_item(6, view)
	while check_nb_player(4) != 1:
		send_to_server("Broadcast wait level up:5.")
		check_level_reception(receive_from_server())
	send_to_server("Broadcast go level_up:5 ")
	check_level_reception(receive_from_server())
	return pass_level()

def pass_level_6(view):
	take_too_many_item(1, view, 1)
	take_too_many_item(2, view, 2)
	take_too_many_item(1, view, 3)
	take_too_many_item(3, view, 4)
	pick_useless_item(5, view)
	pick_useless_item(6, view)
	while check_nb_player(4) != 1:
		send_to_server("Broadcast wait level up:6.")
		check_level_reception(receive_from_server())
	send_to_server("Broadcast go level_up:6 ")
	check_level_reception(receive_from_server())
	return pass_level()

def go_left():
	send_to_server("Left")
	check_reception(receive_from_server())
	send_to_server("Forward")
	check_reception(receive_from_server())
	send_to_server("Right")
	check_reception(receive_from_server())
	send_to_server("Forward")
	check_reception(receive_from_server())

def go_right():
	send_to_server("Right")
	check_reception(receive_from_server())
	send_to_server("Forward")
	check_reception(receive_from_server())
	send_to_server("Left")
	check_reception(receive_from_server())
	send_to_server("Forward")
	check_reception(receive_from_server())

def check_direction(view):
	if view[2] == "":
		if view[1] != "": go_left()
		elif view[3] != "": go_right()
		elif level[0] >= 2:
			if view[4] != "":
				go_left()
				go_left()
			elif view[5] != "":
				go_left()
				send_to_server("Forward")
				check_reception(receive_from_server())
			elif view[6] != "":
				send_to_server("Forward")
				check_reception(receive_from_server())
				send_to_server("Forward")
				check_reception(receive_from_server())
			elif view[7] != "":
				go_right()
				send_to_server("Forward")
				check_reception(receive_from_server())
			elif view[8] != "":
				go_right()
				go_right()
			else:
				send_to_server("Forward")
				check_reception(receive_from_server())
				send_to_server("Forward")
				check_reception(receive_from_server())
	else:
		send_to_server("Forward")
		check_reception(receive_from_server())

def take_all(view):
	for a in re.finditer("food", view[0]):
		send_to_server("Take " + "food")
		check_reception(receive_from_server())
	for idx in range(1, 7):
		if view[0].find(inv[idx]) != -1:
			send_to_server("Take " + inv[idx])
			check_reception(receive_from_server())

def check_level_2(view):
	if level[0] == 2:
		count = 0
		for idx in range(1, 4):
			if view[0].find(inv[idx]) != -1 or inventory[idx] >= 1: count += 1
		if count == 3: return 1
	return 0

def check_level_3(view):
	if level[0] == 3:
		count = 0
		if inventory[1] >= 2: count += 1
		if inventory[3] >= 1: count += 1
		if inventory[5] >= 2: count += 1
		if count == 3: return 1
	return 0

def check_level_4(view):
	if level[0] == 4:
		count = 0
		if inventory[1] >= 1: count += 1
		if inventory[2] >= 1: count += 1
		if inventory[3] >= 2: count += 1
		if inventory[5] >= 1: count += 1
		if count == 4: return 1
	return 0

def check_level_5(view):
	if level[0] == 5:
		count = 0
		if inventory[1] >= 1: count += 1
		if inventory[2] >= 2: count += 1
		if inventory[3] >= 1: count += 1
		if inventory[4] >= 3: count += 1
		if count == 4: return 1
	return 0

def check_level_6(view):
	if level[0] == 6:
		count = 0
		if inventory[1] >= 1: count += 1
		if inventory[2] >= 2: count += 1
		if inventory[3] >= 3: count += 1
		if inventory[5] >= 1: count += 1
		if count == 4: return 1
	return 0

def check_level_7(view):
	if level[0] == 7:
		count = 0
		if inventory[1] >= 2: count += 1
		if inventory[2] >= 2: count += 1
		if inventory[3] >= 2: count += 1
		if inventory[4] >= 2: count += 1
		if inventory[5] >= 2: count += 1
		if inventory[6] >= 1: count += 1
		if count == 6: return 1
	return 0

def check_incantation(view):
	if view[0].find("linemate") != -1 and level[0] == 1: return pass_level_2(view)
	if inventory[0] > 30:
		if check_level_2(view) == 1: pass_level_3(view)
	if inventory[0] > 50:
		if check_level_4(view) == 1: pass_level_5(view)
	if check_level_3(view) == 1: pass_level_4(view)
	elif check_level_5(view) == 1: pass_level_6(view)
	return 0

def check_view(message):
	view = message.replace("[ ", "", -1).replace(" ]\n", "", -1).replace(", ", ",", -1).split(",", -1)
	if check_incantation(view) == 1: check_direction(view)
	else: take_all(view)
	check_direction(view)

def reach_ia(direction):
	if direction == 1:
		send_to_server("Forward")
		broadcast_reception(receive_from_server())
	elif direction == 2:
		send_to_server("Left")
		check_reception(receive_from_server())
		send_to_server("Forward")
		check_reception(receive_from_server())
		send_to_server("Right")
		broadcast_reception(receive_from_server())
	elif direction == 3:
		send_to_server("Left")
		broadcast_reception(receive_from_server())
	elif direction == 4:
		send_to_server("Left")
		check_reception(receive_from_server())
		send_to_server("Left")
		check_reception(receive_from_server())
		send_to_server("Forward")
		check_reception(receive_from_server())
		send_to_server("Right")
		broadcast_reception(receive_from_server())
	elif direction == 5:
		send_to_server("Left")
		check_reception(receive_from_server())
		send_to_server("Left")
		broadcast_reception(receive_from_server())
	elif direction == 6:
		send_to_server("Right")
		check_reception(receive_from_server())
		send_to_server("Right")
		check_reception(receive_from_server())
		send_to_server("Forward")
		check_reception(receive_from_server())
		send_to_server("Left")
		broadcast_reception(receive_from_server())
	elif direction == 7:
		send_to_server("Right")
		check_reception(receive_from_server())
		send_to_server("Forward")
		broadcast_reception(receive_from_server())
	elif direction == 8:
		send_to_server("Right")
		check_reception(receive_from_server())
		send_to_server("Forward")
		check_reception(receive_from_server())
		send_to_server("Left")
		broadcast_reception(receive_from_server())
	else:
		broadcast_reception(receive_from_server())

def broadcast_reception(message):
	print_server(message)
	message.replace("ok", "", -1).replace("ko", "", -1)
	if message.find("dead\n") != -1: print_death()
	elif message.find("message ") != -1 and message.find("wait level up:") != -1 :
		to_level = int(message.replace(" ", "", -1).split("message", -1)[1].split(":", -1)[1].split(".", -1)[0])
		direction = int(message.replace(",", "", -1).split("message", -1)[1].split(" ", -1)[1].split(",", -1)[0])
		if to_level == level[0] + 1 and inventory[0] > 20:
			reach_ia(direction)
		else: return 1
	elif message.find("message ") != -1 and message.find("go level up:") != -1 :
		return 1
	elif message.find("Current level: ") != -1: change_level(message)
	else: reach_ia(message)

def check_reception(message):
	print_server(message)
	if message.find("ko\n") != -1: return 1
	elif message.find("ok\n") != -1: return 0
	elif message.find("dead\n") != -1: print_death()
	elif message.find("message ") != -1: return broadcast_reception(message)
	elif message.find("[ player") != -1: check_view(message)
	elif message.find("[ food ") != -1 and message.find(", linemate ") != -1 and message.find(", deraumere ") != -1 and message.find(", sibur ") != -1 and message.find(", mendiane ") != -1 and message.find(", phiras ") != -1 and message.find(", thystame ") != -1: update_inventory(message)
	elif message.find("Current level: ") != -1: change_level(message)
	return 0

def IA():
	while alive == 1:
		send_to_server("Inventory")
		check_reception(receive_from_server())
		send_to_server("Look")
		check_reception(receive_from_server())
	
def main():
	if (len(sys.argv) == 2 and argv[1] == "-h"):
		print_help()
	elif (len(sys.argv) == 5 or len(sys.argv) == 7):
		check_error()
		start_connection()
		IA()
		disconnect_from_server()									
	else:
		print_help()
		exit(84)
	exit(0)

if __name__ == "__main__":
	main()
