/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** main.c
*/

#include "asm.h"

int main(int argc, char **argv)
{
    data_t *data = malloc(sizeof(data_t));

    init_all(data);
    if (error_handle(argc, argv, data) == 1) {
        free_all(data);
        return 84;
    }
    if (fill_read_header(data, argv[1]) == 84)
        return 84;
    if (write_instruction(data) == 84)
        return 84;
    free_all(data);
    return 0;
}
