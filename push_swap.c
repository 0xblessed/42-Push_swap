#include "push_swap.h"
# include    "libft/libft.h"

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
    NODE* curr = *root;
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    curr->next = new_node;
}

void inicializar_stack(NODE *root, char **argv, int argc)
{
    int i = 2;
    int j = 1;
    if (argc == -1)
    {
        //bucle del split
        root->x = ft_atoi(argv[0]);
        while (argv[j] != NULL)
        {
            insertar_stack(&root, ft_atoi(argv[j]));
            j++;
        }
        
    }
    else
    {
        root->x = ft_atoi(argv[1]);
    
        while(i < argc)
        {
            insertar_stack(&root, ft_atoi(argv[i]));
            i++;
        }
    }
    
    
}

/*int main(int argc, char **argv)
{
    if (argc < 1)
    {
        NODE *stackA = malloc(sizeof(NODE));
        NODE *stackB = malloc(sizeof(NODE));
    
        
        if (argc == 2)
        {
            inicializar_stack(stackA, ft_split(argv[1], ' '), -1);
        }
        else
        {
            inicializar_stack(stackA, argv, argc);
        }
        
        //Printa el stack
        NODE *curr = malloc(sizeof(NODE));
        curr = stackA;
    
        while(curr != NULL)
        {
            printf("%d\n", curr->x);
            curr = curr->next;
        }
    }
    else
    {
        write(1, "Error", 5);
    }
}*/
int main(int argc, char **argv) {
    if (argc > 1) {
        NODE *stackA = malloc(sizeof(NODE));
        NODE *stackB = malloc(sizeof(NODE));

        if (argc == 2) {
            inicializar_stack(stackA, ft_split(argv[1], ' '), -1);
        } else {
            inicializar_stack(stackA, argv, argc);
        }

        // Imprime el stack
        NODE *curr = stackA;

        while (curr != NULL) {
            printf("%d\n", curr->x);
            curr = curr->next;
        }
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}