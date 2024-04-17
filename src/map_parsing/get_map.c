/*
** EPITECH PROJECT, 2024
** get map
** File description:
** function to get the map
*/

#include <SFML/Graphics.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map_correspondance.h"
#include "functions.h"
#include "libmy.h"
#include "floor_struct.h"

static bool fill_sprite(char character, floor_t **sprite,
    sfTexture ***textures, size_t type)
{
    for (size_t j = 0; MAP_CORESPONDANCE[type][j]; ++j) {
        if (MAP_CORESPONDANCE[type][j] == character)
            *sprite = INIT_MAP_FUNC[type](textures[type][j], character, type);
        else
            continue;
        if (*sprite == NULL)
            return false;
        return true;
    }
    *sprite = INIT_MAP_FUNC[type](NULL, '\0', 0);
    return (*sprite == NULL) ? false : true;
}

static bool fill_sprite_line(char const *const char_line,
    floor_t **sprite_line, sfTexture ***textures, size_t type)
{
    size_t i = 0;

    while (char_line[i] != '\0') {
        if (!fill_sprite(char_line[i], &sprite_line[i], textures, type)) {
            return false;
        }
        ++i;
    }
    return true;
}

static floor_t ***get_sprite_map(char const *const *const char_map,
    sfTexture ***textures, size_t type)
{
    floor_t ***sprites = calloc(sizeof(floor_t **),
        my_arraylen(char_map) + 1);

    for (size_t j = 0; char_map[j]; ++j) {
        sprites[j] = calloc(sizeof(floor_t *), strlen(char_map[j]) + 1);
        if (sprites[j] == NULL)
            return NULL;
        if (!fill_sprite_line(char_map[j], sprites[j], textures, type))
            return NULL;
    }
    for (size_t i = 0; sprites[i]; ++i)
        for (size_t j = 0; sprites[i][j]; ++j) {
            sfSprite_setPosition(sprites[i][j]->sprite,
            (sfVector2f){25.0 * j, 25.0 * i});
        }
    return sprites;
}

floor_t ***get_map(sfTexture ***texture, size_t type)
{
    char **char_map = get_char_map(type);

    if (char_map == NULL)
        return NULL;
    return get_sprite_map((char const *const *const)char_map, texture, type);
}
