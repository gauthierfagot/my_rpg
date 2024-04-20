/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "functions.h"
#include "enums/textures.h"
#include "floor_struct.h"

static void draw_map(sfRenderWindow *wnd, floor_t ***floor)
{
    for (int i = 0; floor[i]; ++i) {
        for (int j = 0; floor[i][j]; ++j) {
            sfRenderWindow_drawSprite(wnd, floor[i][j]->sprite, NULL);
        }
    }
}

static bool start_window(floor_t ***floor, floor_t ***structures, floor_t ***colision)
{
    sfRenderWindow *wnd = sfRenderWindow_create((sfVideoMode){1000, 500, 100}, "my rpg", 4 | 2, NULL);
    sfEvent event;

    while (sfRenderWindow_isOpen(wnd)) {
        draw_map(wnd, floor);
        draw_map(wnd, structures);
        draw_map(wnd, colision);
        while (sfRenderWindow_pollEvent(wnd, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wnd);
        }
        sfRenderWindow_display(wnd);
        sfRenderWindow_clear(wnd, sfBlack);
    }
    return true;
}

int main(int argc, char **argv, char **env)
{
    sfTexture ***textures = init_textures();
    floor_t ***floor = NULL;
    floor_t ***structures = NULL;
	floor_t ***colision = NULL;

    if (textures == NULL)
        return 84;
    floor = get_map(textures, FLOOR);
    structures = get_map(textures, STRUCTURE);
	colision = get_map(textures, COLISIONS);
    if (floor == NULL || structures == NULL)
        return 84;
    start_window(floor, structures, colision);
    return 0;
}
