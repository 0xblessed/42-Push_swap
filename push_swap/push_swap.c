#include "push_swap.h"

int main()
{
    printf("Hola Mundo\n");
    size_t i = ft_strlen("CACA");
    printf("%d", (int)i);
}
/*
void insertar_stack(NODE** root, int value)
{
    NODE* new_node = malloc(sizeof(NODE));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->x = value;
    new_node->next = NULL;
    
    if(*root == NULL)
    {
        *root = new_node;
        return ; 
    }
    NODE* curr = *root;;
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    curr->next = new_node;
}

void inicializar_stack(NODE *root)
{
    root->x = 7;
    insertar_stack(&root, 5);
    insertar_stack(&root, 77);
}

int main(int argc, char **argv)
{
    NODE *stackA = malloc(sizeof(NODE));
    
    inicializar_stack(stackA);
    //Printa el stack
    NODE *curr = malloc(sizeof(NODE));
    curr = stackA;
    
    
    while(curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }
    return 0;
}*/