/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** ecs
*/

#ifndef ECS_H_
    #define ECS_H_

    #include <stddef.h>
    #include "vector.h"

typedef struct entity_system {
    vec_t *entity_state;
    vec_t *components;
}entity_system_t;

#endif
