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

static const char *MAP_CORESPONDANCE[] = {
    "#+~T",
    NULL,
};

sfSprite *init_floor_case(sfTexture *texture);

static sfSprite *(*INIT_MAP_FUNC[])(sfTexture *) = {
    init_floor_case,
};

#endif
