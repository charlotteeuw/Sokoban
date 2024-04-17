/*
** EPITECH PROJECT, 2023
** $IS_VALID
** File description:
** Checks if file is valid
*/

#include "../include/sokoban.h"

void open_file(char *filepath, map_t *map)
{
    int number_lines;
    int nb_columns;
    int fd = open(filepath, O_RDONLY);
    struct stat file_type;
    char *buffer;
    int size = 0;
    int size_read = 0;

    stat(filepath, &file_type);
    size = file_type.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    size_read = read(fd, buffer, size);
    if (filepath == NULL || fd < 0 || size_read < 0)
        exit(84);
    buffer[size] = '\0';
    number_lines = count_nb_lines(buffer);
    nb_columns = count_nb_columns(buffer);
    if (valid_char(buffer, map) == 0)
        buffer_into_tab(buffer, fd, number_lines, map);
}

int valid_char(char *buffer, map_t *map)
{
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] != ' ' && buffer[j] != 'X' && buffer[j] != '\n'
    && buffer[j] != 'P' && buffer[j] != 'O' && buffer[j] != '#')
            exit(84);
    }
    map->buffer = buffer;
    return 0;
}

void buffer_into_tab(char *buffer, int fd, int number_lines, map_t *map)
{
    int j = 0;
    char **tab = malloc(sizeof(char *) * (number_lines + 1));
    int k = 0;
    int i = 0;
    int nb_cols = 0;

    for (i; i < number_lines; i++) {
        j = 0;
        nb_cols = count_nb_columns(&buffer[k]);
        tab[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (j; j < nb_cols; j++) {
            tab[i][j] = buffer[k];
            k++;
        }
        tab[i][j] = '\0';
        k++;
    }
    tab[i] = NULL;
    close(fd);
    call_functions(map, tab, number_lines);
}

void in_copymap(map_t *map, int i, int j)
{
    if (map->map[i][j] == 'X' || map->map[i][j] == 'P')
        map->original_map[i][j] = ' ';
    else
        map->original_map[i][j] = map->map[i][j];
}

void copy_map(map_t *map, int number_lines)
{
    map->original_map = malloc(sizeof(char *) * number_lines);
    for (int i = 0; i < number_lines; i++) {
        map->original_map[i] = malloc(sizeof(char)
    * count_nb_columns(map->map[i]));
        for (int j = 0; j < count_nb_columns(map->map[i]); j++) {
            in_copymap(map, i, j);
        }
    }
}
