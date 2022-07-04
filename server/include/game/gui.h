/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** header
*/

#ifndef GUi_GAME_HEADER
#define GUi_GAME_HEADER

/* Includes */
#include "../server.h"

/* Prototypes */
void call_gui(server_info_t *serv_info, char *command, user_t *user);
void send_tile(server_info_t *serv, user_t *usr, int x, int y);

typedef void (*fp)(server_info_t *, char *, user_t *);

void command_mcz(server_info_t *serv, char *cmd, user_t *usr);
void command_bct(server_info_t *serv, char *cmd, user_t *usr);
void command_mct(server_info_t *serv, char *cmd, user_t *usr);
void command_tna(server_info_t *serv, char *cmd, user_t *usr);
void command_ppo(server_info_t *serv, char *cmd, user_t *usr);
void command_plv(server_info_t *serv, char *cmd, user_t *usr);
void command_pin(server_info_t *serv, char *cmd, user_t *usr);
void command_sgt(server_info_t *serv, char *cmd, user_t *usr);
void command_sst(server_info_t *serv, char *cmd, user_t *usr);

static const int TAB_SIZE = 9;

typedef struct cmd_gui_s
{
    char *name;
    fp function;
} cmd_gui_t;

static const cmd_gui_t TAB_GUI[] = {
    {"mcz\n", command_mcz},
    {"bct\n", command_bct},
    {"mct\n", command_mct},
    {"tna\n", command_tna},
    {"ppo\n", command_ppo},
    {"plv\n", command_plv},
    {"pin\n", command_pin},
    {"sgt\n", command_sgt},
    {"sst\n", command_sst},
};

#endif /*GUi_GAME*/