/*
** EPITECH PROJECT, 2023
** sprite size
** File description:
** return the apropriate scale of the sprite
*/

#include <SFML/Graphics.h>
#include <math.h>

sfVector2f sprite_size(sfTexture *text, sfVector2f size)
{
    double original_x = pow(sfTexture_getSize(text).x, -1);
    double original_y = pow(sfTexture_getSize(text).y, -1);

    return (sfVector2f){size.x * original_x, size.y * original_y};
}
