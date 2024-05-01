/*
** EPITECH PROJECT, 2024
** drawing system
** File description:
** drawing system
*/

#include <SFML/Graphics.h>
#include "ecs.h"
#include "components.h"
#include "filter_entity.h"

void draw_entities(entity_system_t *es, sfRenderWindow *wnd)
{
    entity_filter_t *filter = filter_entities(2, es, DRAW, POSITION);
    vec_t *component_draw = (vec_t *)(es->components[DRAW]);
    vec_t *component_position = (vec_t *)(es->components[POSITION]);
    c_draw_t *tmp_draw = NULL;
    c_position_t *tmp_pos = NULL;

    for (int i = 0; i < filter->number; ++i) {
        tmp_draw = (c_draw_t *)
            ((void **)component_draw->data)[filter->indexes[i]];
        tmp_pos = (c_position_t *)
            ((void **)component_position->data)[filter->indexes[i]];
        sfSprite_setPosition(tmp_draw->sprite, tmp_pos->pos);
        sfRenderWindow_drawSprite(wnd, tmp_draw->sprite, NULL);
    }
    free_filter(filter);
}
