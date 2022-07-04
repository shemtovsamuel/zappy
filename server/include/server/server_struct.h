/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** header
*/

#ifndef SERVER_STRUCT_HEADER
#define SERVER_STRUCT_HEADER

/* Includes */
#include "../../../libs/ll_lib/ll.h"
#include "../global/struct.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <sys/select.h>

/* Const */
static const bool bread = true;
static const bool bwrite = false;
static const bool Player = true;
static const bool Graphical = false;

/* Enum */
typedef enum user_mode_s {
    UNSET = 0,
    GUI,
    PLAYER,
} user_mode_t;

/* Modules */
typedef struct client_s {
    int nb;
    struct sockaddr_in clientSocket;
    socklen_t socketSize;
} client_t;

typedef struct user_s {
    int socket;

    bool listing_type;
    list_t answer;

    user_mode_t user_type;
    union
    {
        player_t player;
        gui_t gui;
    };
} user_t;

typedef struct server_info_s {
    int socket;
    bool bsocket;
    database_t data;
    list_t user_list;
    char *buf;
    int nb;
} server_info_t;

#endif /*SERVER_STRUCT*/