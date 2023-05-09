/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_virtual_machine.c
*/

#include "corewar.h"

static void init_simple_value(vm_t *vm)
{
    vm->cycle_max = -1;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->actual_cycle = 0;
    vm->champ_actu = 0;
}

int init_vm(UNUSED char **argv, vm_t *vm)
{
    init_simple_value(vm);
    if ((vm->buffer = my_calloc(MEM_SIZE)) == NULL) {
        free(vm);
        return 84;
    }
    if ((vm->champion = malloc(sizeof(champion_t) * (4 + 1))) == NULL) {
        free_all(vm, NONE_C);
        return 84;
    }
    if (init_champ(vm) != 0)
        return 84;
    if (check_argv(argv, vm) != 0) {
        free_all(vm, ALL);
        return 84;
    }
    return 0;
}
