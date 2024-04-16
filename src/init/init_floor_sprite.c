/*
** EPITECH PROJECT, 2024
** init floor
** File description:
** int floor case
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "functions.h"
#include "size/floor_size.h"

sfSprite *init_floor_case(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return NULL;
    sfSprite_setTexture(sprite, texture, true);
    sfSprite_setScale(sprite, sprite_size(texture, FLOOR_SIZE));
    return sprite;
}
