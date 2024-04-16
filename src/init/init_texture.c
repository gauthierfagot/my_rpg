/*
** EPITECH PROJECT, 2024
** init textures
** File description:
** init the textures
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "libmy.h"
#include "texture_init.h"

sfTexture **init_texture_array(size_t i)
{
    sfTexture **array = calloc(sizeof(sfTexture *),
        (my_arraylen(INIT_TEXTURE_TAB[i]) + 1));

    if (array == NULL)
        return NULL;
    for (size_t j = 0; INIT_TEXTURE_TAB[i][j] != NULL; ++j) {
        array[j] = sfTexture_createFromFile(INIT_TEXTURE_TAB[i][j], NULL);
        if (array[j] == NULL)
            return NULL;
    }
    return array;
}

sfTexture ***init_textures(void)
{
    sfTexture ***array = calloc(sizeof(sfTexture **), (TEXTURE_TAB_S + 1));

    if (array == NULL)
        return NULL;
    for (size_t i = 0; i < TEXTURE_TAB_S; i++) {
        array[i] = init_texture_array(i);
        if (array[i] == NULL)
            return NULL;
    }
    return array;
}
