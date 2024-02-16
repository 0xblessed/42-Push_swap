#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include    "libft/libft.h"
# include    <stdio.h>
# include    <stdlib.h>
# include    <limits.h>

// Structs
typedef struct NODE
{
    int x;
    int index;
    struct NODE *next;
    struct NODE *previous;

}NODE;

//Funciones

void imprime_stack(NODE *stackA); 
void insertar_stack(NODE** root, int value);
void inicializar_stack(NODE *root, char **argv, int argc);
void asignacion_indices(NODE* head);
void ra(NODE **stack);
void inserta_arriba(NODE *node, NODE **stackB);
void pb(NODE** stackA, NODE** stackB);
void conectar(NODE **stackA, NODE **stackB);
#endif