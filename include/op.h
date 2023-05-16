/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** op.h
*/

#ifndef _OP_H_
    #define _OP_H_
    #define MEM_SIZE                (6 * 1024)
    #define MEM_Y                   96
    #define MEM_X                   64

    #define IDX_MOD                 512   /* modulo of the index < */
    #define MAX_ARGS_NUMBER         4
    /* this may not be changed 2 ^ *IND_SIZE */

    # define COMMENT_CHAR            '#'
    # define LABEL_CHAR              ':'
    # define DIRECT_CHAR             '%'
    # define SEPARATOR_CHAR          ','

    # define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    # define NAME_CMD_STRING         ".name"
    # define COMMENT_CMD_STRING      ".comment"

/*
** regs
*/

    # define REG_NUMBER      16              /* r1 <--> rx */

/*
**
*/

typedef char    args_type_t;

    # define T_REG           1       /* register */
    # define T_DIR           2       /* direct  (ld  #1,r1  put 1 into r1) */
    # define T_IND           4       /* indirect always relative
                                   ( ld 1,r1 put what's in the address (1+pc)
                                   into r1 (4 bytes )) */
    # define T_LAB           8       /* LABEL */

typedef struct op_s {
    char         *mnemonique;
    char         nbr_args;
    args_type_t  type[MAX_ARGS_NUMBER];
    char         code;
    int          nbr_cycles;
    int          hexa_value;
    char         *comment;
} op_t ;

/*
** size (in bytes)
*/
    # define IND_SIZE        2
    # define DIR_SIZE        4
    # define REG_SIZE        DIR_SIZE

static const op_t op_tab[] =
        {
        {
            "live", 1,
            {T_DIR},
            1, 10, 0x01,"alive"
            },
            {
            "ld", 2,
            {T_DIR | T_IND, T_REG},
            2, 5, 0x02,"load"
            },
        {
            "st", 2,
            {T_REG, T_IND | T_REG},
            3, 5, 0x03,"store"
            },
        {
            "add", 3,
            {T_REG, T_REG, T_REG},
            4, 10, 0x04,"addition"
            },
        {
            "sub", 3,
            {T_REG, T_REG, T_REG},
            5, 10, 0x05,"soustraction"
            },
        {
            "and", 3,
            {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
            6, 6, 0x06,"et (and  r1, r2, r3   r1&r2 -> r3"
            },
        {
            "or", 3,
            {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
            7, 6, 0x07,"ou  (or   r1, r2, r3   r1 | r2 -> r3"
            },
        {
            "xor", 3,
            {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
            8, 6, 0x08,"ou (xor  r1, r2, r3   r1^r2 -> r3"
            },
        {
            "zjmp", 1,
            {T_DIR},
            9, 20, 0x09,"jump if zero"
            },
        {
            "ldi", 3,
            {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
            10, 25, 0x0a,"load index"
            },
        {
            "sti", 3,
            {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
            11, 25, 0x0b,"store index"
            },
        {
            "fork", 1,
            {T_DIR},
            12, 800, 0x0c,"fork"
            },
        {
            "lld", 2,
            {T_DIR | T_IND, T_REG},
            13, 10, 0x0d,"long load"
            },
        {
            "lldi", 3,
            {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
            14, 50, 0x0e,"long load index"
            },
        {
            "lfork", 1,
            {T_DIR},
            15, 1000, 0x0f,"long fork"
            },
        {
            "aff", 1,
            {T_REG},
            16, 2, 0x10,"aff"
            },
        {
            0, 0,
            {0},
            0, 0, 0x00,0
            }
        };
//TODO : ask to aer why miss 16 char
    # define PROG_NAME_LENGTH        128 + 16
    # define COMMENT_LENGTH          2048

typedef struct header_s {
    int  magic;
    # define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
}header_t;

    # define CYCLE_TO_DIE    1536
    # define CYCLE_DELTA     5
    # define NBR_LIVE        40

#endif
