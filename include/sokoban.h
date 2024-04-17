/*
** EPITECH PROJECT, 2023
** $MY_LS.H
** File description:
** My_ls.h
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <stddef.h>
    #include <signal.h>
    #include <stdio.h>
    #include <curses.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>


typedef struct position_s {
    int player_x;
    int player_y;
} position_t;

typedef struct map_s {
    char **map;
    char **original_map;
    char **real_map;
    char *buffer;
    position_t position;
    int is_stuck;
    int counter;
} map_t;

void main(int argc, char **argv);
void information(void);
int sokoban(map_t *map);
void open_file(char *filepath, map_t *map);
int valid_char(char *buffer, map_t *map);
void buffer_into_tab(char *buffer, int fd, int number_lines, map_t *map);
int count_nb_lines(char *buffer);
int count_nb_columns(char *buffer);
int display_map(map_t *tab);
int key_pressed(map_t *map);
void player_position(map_t *map);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int check_win(map_t *map);
char *my_strcpy(char *dest, char const *src);
void copy_map(map_t *map, int number_lines);
int check_win(map_t *map);
int number_of_boxes(map_t *map);
int number_of_locations(map_t *map);
void in_if(map_t *map, int *nb_locations, int i, int j);
void call_functions(map_t *map, char **tab, int number_lines);
void copy_real_map(map_t *map, int number_lines);
int move_player(map_t *map, int direction_x, int direction_y);
int check_loss(map_t *map);
int stuck(map_t *map, int next_x, int next_y);
void call_stuck(map_t *map, int box_next_x, int box_next_y);
void display_map2(map_t *tab);

#endif
