/*
** EPITECH PROJECT, 2024
** init floor
** File description:
** int floor case
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "floor_struct.h"
#include "functions.h"
#include "size/floor_size.h"
#include "enums/textures.h"
#include "map_correspondance.h"

floor_t *init_floor_case(sfTexture *texture, char c, size_t type)
{
    floor_t *new = calloc(sizeof(floor_t), 1);

    if (new == NULL)
        return NULL;
    new->sprite = sfSprite_create();
    if (new->sprite == NULL)
        return NULL;
    if (texture != NULL) {
        sfSprite_setTexture(new->sprite, texture, true);
    }
    new->size = (sfVector2i){1, 1};
    for (size_t i = 0; MAP_CORESPONDANCE[type][i]; i++)
        if (c == MAP_CORESPONDANCE[type][i]) {
            new->colision = COLISION[type][i];
            sfSprite_setScale(new->sprite,
                sprite_size(texture, ELEMENTS_SIZE[type][i]));
            sfSprite_setOrigin(new->sprite,
                (sfVector2f){0.0, sfTexture_getSize(texture).y});
        }
    return new;
}
