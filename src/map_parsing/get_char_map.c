/*
** EPITECH PROJECT, 2024
** get char map
** File description:
** get char map
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "libmy.h"
#include "enums/maps.h"

char **get_char_map(size_t type)
{
    char *buffer = get_buffer(MAPS[type]);

    if (buffer == NULL)
        return NULL;
    return format_line(buffer, "\n", "");
}
