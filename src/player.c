/*
** EPITECH PROJECT, 2023
** $PLAYER
** File description:
** Sokoban
*/

#include "../include/sokoban.h"

void if_player(map_t *map, int i, int j)
{
    if (map->map[i][j] == 'P') {
        map->position.player_x = j;
        map->position.player_y = i;
        map->map[i][j] = map->original_map[i][j];
    }
}

void player_position(map_t *map)
{
    map->position.player_x = 0;
    map->position.player_y = 0;
    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            if_player(map, i, j);
        }
    }
}

void change_map(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            map->map[i][j] = map->real_map[i][j];
        }
    }
}

int key_pressed(map_t *map)
{
    int key = getch();

    switch (key) {
        case KEY_UP:
            return move_player(map, 0, -1);
        case KEY_DOWN:
            return move_player(map, 0, 1);
        case KEY_RIGHT:
            return move_player(map, 1, 0);
        case KEY_LEFT:
            return move_player(map, -1, 0);
        case 'q':
            return 1;
        case ' ':
            change_map(map);
            sokoban(map);
            return 1;
    }
    return 0;
}

int move_player(map_t *map, int direction_x, int direction_y)
{
    int next_x = map->position.player_x + direction_x;
    int next_y = map->position.player_y + direction_y;
    int box_next_x = next_x + direction_x;
    int box_next_y = next_y + direction_y;

    if (map->map[next_y][next_x] == '#')
        return 0;
    if (map->map[next_y][next_x] == 'X') {
        if (map->map[box_next_y][box_next_x] == ' ' ||
    map->map[box_next_y][box_next_x] == 'O') {
            map->map[next_y][next_x] = map->original_map[next_y][next_x];
            map->map[box_next_y][box_next_x] = 'X';
            call_stuck(map, box_next_x, box_next_y);
        } else
            return 0;
    }
    map->position.player_x = next_x;
    map->position.player_y = next_y;
    return 0;
}
