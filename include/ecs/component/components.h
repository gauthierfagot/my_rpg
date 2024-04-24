/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** component
*/

#pragma once

    #include <stddef.h>
    #include "my_toml.h"
    #include "type_create.h"
    #include "position_component.h"
    #include "health_component.h"
    #include "velocity_component.h"
    #include "draw_component.h"
    #include "text_component.h"
    #include "key_pressed_component.h"
    #include "mouse_pressed_component.h"
    #include "ecs.h"

entity_system_t *init_entity_system(entity_system_t *es);

typedef enum component_e {
    POSITION = 0,
    HEALTH,
    VELOCITY,
    DRAW,
    TEXT,
    KEY_PRESSED,
    MOUSE_PRESSED,
    GAME_MODE,
    LAST_COMPONENT
} component_t;

typedef struct component_data_s {
    char *name;
    component_t index;
    int (*init)();
    size_t size;
} component_data_t;

// int init_component_position(entity_system_t *es,
//     obj_t *, component_t, int entity);
// int init_component_velocity(entity_system_t *es,
//     obj_t *, component_t, int entity);
// int init_component_health(entity_system_t *es,
//     obj_t *, component_t, int entity);
int init_component_draw(entity_system_t *es,
    obj_t *, component_t, int entity);
// int init_component_text(entity_system_t *es,
//     obj_t *, component_t, int entity);
// int init_component_key_pressed(entity_system_t *es,
//     obj_t *, component_t, int entity);
// int init_component_mouse_pressed(entity_system_t *es, obj_t *,
//     component_t, int entity);
int init_component_game_mode(entity_system_t *es, obj_t *,
    component_t, int entity);

static const component_data_t COMPONENT_INIT_DATA[] = {
    // {
    //     "POSITION", POSITION, &init_component_position, sizeof(c_position_t)
    // },
    // {
    //     "HEALTH", HEALTH, &init_component_health, sizeof(c_health_t)
    // },
    // {
    //     "VELOCITY", VELOCITY, &init_component_velocity, sizeof(c_velocity_t)
    // },
    {
        "DRAW", DRAW, &init_component_draw, sizeof(c_draw_t)
    },
    // {
    //     "TEXT", TEXT, &init_component_text, sizeof(c_text_t)
    // },
    // {
    //     "KEY_PRESSED", KEY_PRESSED, &init_component_key_pressed,
    //     sizeof(c_key_pressed_t)
    // },
    // {
    //     "MOUSE_PRESSED", MOUSE_PRESSED, &init_component_mouse_pressed,
    //     sizeof(c_mouse_pressed_t)
    // }
    {
        "GAME_MODE", GAME_MODE, &init_component_game_mode,
        sizeof(c_game_mode_t)
    }
};
