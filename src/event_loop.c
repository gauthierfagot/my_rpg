/*
** EPITECH PROJECT, 2024
** event_loop.c
** File description:
** event_loop
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"
#include "key_mapping.h"
#include "macro.h"
#include "launcher.h"
#include "vector.h"
#include "ecs.h"
#include "filter_entity.h"
#include "systems.h"

static void execute_keys(entity_system_t *es, sfEvent *event)
{
    for (int i = 0; i < ACTION_COUNT; i++) {
        if (es->keys[es->game_mode].key_map[i] == NULL) {
            continue;
        }
        if (event->type == sfEvtKeyPressed &&
            event->key.code == es->keys[es->game_mode].key_map[i]->key) {
            es->keys[es->game_mode].key_map[i]->callback(es);
            return;
        }
    }
}

static void handle_event(sfRenderWindow *wnd,
    sfEvent *event, entity_system_t *es)
{
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(wnd);
    }
    if (event->type == sfEvtKeyPressed) {
        execute_keys(es, event);
    }
}

void event_loop(sfRenderWindow *wnd, sfEvent *event, entity_system_t *es)
{
    while (sfRenderWindow_pollEvent(wnd, event))
        handle_event(wnd, event, es);
}
