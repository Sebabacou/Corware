/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_fork.c
*/

#include "corewar.h"

int fct_fork(vm_t *vm)
{
    size_t parameter = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 1,
                                  VM_PROCESS_ACTU->pos_y, DIR_SIZE);

    VM_CHAMP_ACTU.process_actu++;
    init_process(vm);
    move_process(vm, VM_CHAMP_ACTU.process[VM_CHAMP_ACTU.process_actu -
    1]->pc + parameter % IDX_MOD);
    VM_PROCESS_ACTU->pc = VM_CHAMP_ACTU.process[VM_CHAMP_ACTU.process_actu -
                                                1]->pc + parameter % IDX_MOD;
    printf("FORK : ");
    printf("PC to go = %ld -> %ld,%ld | ", VM_CHAMP_ACTU.process[VM_CHAMP_ACTU
    .process_actu - 1]->pc + parameter % IDX_MOD, VM_PROCESS_ACTU->pos_y,
           VM_PROCESS_ACTU->pos_x);
    printf("value of %x | ", vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU
    ->pos_x]);
    printf("pos of new process = %d\n", VM_PROCESS_ACTU->pc);
    VM_CHAMP_ACTU.process_actu--;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
