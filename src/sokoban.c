/*
** EPITECH PROJECT, 2023
** $SOKOBAN
** File description:
** Main sokoban function
*/

#include "../include/sokoban.h"

void call_functions(map_t *map, char **tab, int number_lines)
{
    map->map = tab;
    copy_map(map, number_lines);
    copy_real_map(map, number_lines);
    if (number_of_boxes(map) != number_of_locations(map))
        exit(84);
    sokoban(map);
}

int get_max_column(map_t *map)
{
    int counter = 0;
    int max = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\n'
    && map->map[i][j] != '\0'; j++) {
            counter++;
        }
        if (counter > max)
            max = counter;
    }
    return max;
}

void check_end(int *quit, int *win, int *loss, map_t *map)
{
    while (*quit == 0 && *win == 0 && *loss == 0) {
        *quit = display_map(map);
        *win = check_win(map);
        *loss = check_loss(map);
    }
    display_map2(map);
}

int sokoban(map_t *map)
{
    int quit = 0;
    int win = 0;
    int loss = 0;
    int y = 0;
    int x = 0;
    char *str = "Window too small, please enlarge the terminal";

    map->is_stuck = 0;
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    player_position(map);
    getmaxyx(stdscr, y, x);
    if (y < count_nb_lines(map->buffer) && x < get_max_column(map))
        mvprintw(y / 2, (x - my_strlen(str)) / 2, "%s", str);
    check_end(&quit, &win, &loss, map);
    endwin();
    if (loss == 1)
        return 1;
    return 0;
}
