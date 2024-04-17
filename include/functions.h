/*
** EPITECH PROJECT, 2024
** functions
** File description:
** functions for my_rpg
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <SFML/Graphics.h>
    #include <stddef.h>
    #include "floor_struct.h"

//init
sfTexture ***init_textures(void);
char **get_char_map(size_t type);

sfVector2f sprite_size(sfTexture *text, sfVector2f size);
floor_t ***get_map(sfTexture ***texture, size_t type);

#endif
