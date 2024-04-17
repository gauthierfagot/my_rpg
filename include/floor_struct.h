/*
** EPITECH PROJECT, 2024
** floor struct
** File description:
** struct for floor
*/

#ifndef FLOOR_STRUCT_H
    #define FLOOR_STRUCT_H

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct floor_s {
    sfSprite *sprite;
    sfSound *sound;
    sfVector2i size;
    bool colision;
}floor_t;

#endif
