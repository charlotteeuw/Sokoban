/*
** EPITECH PROJECT, 2023
** $CHECK_WIN
** File description:
** Checks if the player won
*/

#include "../include/sokoban.h"

void call_stuck(map_t *map, int box_next_x, int box_next_y)
{
    if (stuck(map, box_next_x, box_next_y) == 1)
        map->is_stuck = 1;
}

int stuck(map_t *map, int next_x, int next_y)
{
    int x = next_x;
    int y = next_y;
    int nb_boxes = number_of_boxes(map);

    if (map->map[y - 1][x] == '#' && map->map[y][x - 1] == '#' ||
    map->map[y - 1][x] == '#' && map->map[y][x + 1] == '#' ||
    map->map[y + 1][x] == '#' && map->map[y][x + 1] == '#' ||
    map->map[y + 1][x] == '#' && map->map[y][x - 1] == '#')
        map->counter++;
    if (nb_boxes == map->counter)
        return 1;
    return 0;
}

int check_loss(map_t *map)
{
    if (map->is_stuck == 1)
        return 1;
    return 0;
}
