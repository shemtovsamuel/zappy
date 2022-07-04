/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** broadcast
*/

#include "game/game_loop.h"

static void broadcast_exec(server_info_t *serv_info, event_to_do_t *event)
{
    user_t *temp;
    int trigonometric_dir = 0;
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);

    printf("broadcast\n");
    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (temp->user_type == PLAYER) {
            trigonometric_dir = get_trigonometric_dir(&serv_info->data.map, 
            &event->user->player, &temp->player);
            sprintf(res, "message %d, %s\n", trigonometric_dir, \
            event->broadcast.text);
            create_message(temp, res);
        }
    }
    free(res);
}

int event_broadcast(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->broadcast.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        broadcast_exec(serv_info, event);
        free(event->broadcast.text);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}