/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory
*/

#include "game/game_loop.h"

static void inventory_exec(user_t *user)
{
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);

    sprintf(res, "[ %s%d%s%d%s%d%s%d%s%d%s%d%s%d ]\n", 
    IVT_BASE[FOOD], user->player.ressource[FOOD], 
    IVT_BASE[LINEMATE], user->player.ressource[LINEMATE], 
    IVT_BASE[DERAUMERE], user->player.ressource[DERAUMERE], 
    IVT_BASE[SIBUR], user->player.ressource[SIBUR], 
    IVT_BASE[MENDIANE], user->player.ressource[MENDIANE], 
    IVT_BASE[PHIRAS], user->player.ressource[PHIRAS], 
    IVT_BASE[THYSTAME], user->player.ressource[THYSTAME]);
    create_message(user, res);
    free(res);
}

int event_inventory(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->inventory.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        inventory_exec(event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}