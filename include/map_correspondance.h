/*
** EPITECH PROJECT, 2024
** map correspondance
** File description:
** map correspondance
*/

#ifndef CORRESPONDANCE_H
    #define CORRESPONDANCE_H

    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include "floor_struct.h"

static const char *MAP_CORESPONDANCE[] = {
    "#+~",
    "HBTtprbgc",
    NULL,
};

static const bool FLOOR_COLISION[] = {
    false,
    false,
    true,
};

static const bool *COLISION[] = {
    FLOOR_COLISION,
};

floor_t *init_floor_case(sfTexture *texture, char c, size_t type);

static floor_t *(*INIT_MAP_FUNC[])(sfTexture *, char, size_t) = {
    init_floor_case,
    init_floor_case,
};

#endif
