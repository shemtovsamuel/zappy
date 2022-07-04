/*
** EPITECH PROJECT, 2022
** cpp_d02a
** File description:
** ex00
*/

#ifndef DOUBLE_LIST_H_
# define DOUBLE_LIST_H_

/*
** Types
*/

#include <stdbool.h>

typedef struct node
{
    void *value;
    struct node *next;
} node_t;

typedef node_t *list_t;

/*
** Functions
*/

/* Informations */

unsigned int    linked_list_get_size(list_t list);
bool            linked_list_is_empty(list_t list);
void            linked_list_dump(list_t list);

/* Modification */

bool    linked_list_add_elem_at_front(list_t *front_ptr, void *elem);
bool    linked_list_add_elem_at_back(list_t *front_ptr, void *elem);
bool    linked_list_add_elem_at_position(list_t *front_ptr, void *elem,
                                        unsigned int position);

bool    linked_list_del_elem_at_front(list_t *front_ptr);
bool    linked_list_del_elem_at_back(list_t *front_ptr);
bool    linked_list_del_elem_at_position(list_t *front_ptr,
                                        unsigned int position);

/* Value Access */

void   *linked_list_get_elem_at_front(list_t list);
void   *linked_list_get_elem_at_back(list_t list);
void   *linked_list_get_elem_at_position(list_t list, unsigned int position);

/* Node Access */

node_t  *linked_list_get_first_node_with_value(list_t list, void *value);

#endif /* !DOUBLE_LIST_H_ */
