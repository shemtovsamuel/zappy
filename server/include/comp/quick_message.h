/*
** EPITECH PROJECT, 2022
** ZAPYY
** File description:
** header
*/

#ifndef QUICK_MESSAGE_UTILS_HEADER
#define QUICK_MESSAGE_UTILS_HEADER

/* Includes */
#include "comp/int_to_str.h" 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Prototypes */
char *add_char_to_msg(char *message, char *string);
char *add_end_to_msg(char *message);
char *add_number_to_msg(char *message, int nbr);

#endif /*QUICK_MESSAGE_UTILS*/