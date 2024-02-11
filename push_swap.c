#include     "push_swap.h"
#include    "libft/libft.h"

void imprime_stack(NODE *stackA)
{
    NODE *curr = stackA;

    printf("Stack A:\tStack B\n");
    while (curr != NULL)
    { 
        printf("Value : %d \tIndice: %d\n", curr->x, curr->index);
        curr = curr->next;
    }
}
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

void asignacion_indices(NODE* head) {
    NODE* current = head;
    int iterador_indice = 0;

    while (current != NULL) {
        int min_value = INT_MAX;
        NODE* min_node = NULL;
        NODE* temp = head; // Utilizamos un nodo temporal para iterar sobre la lista internamente

        // Encuentra el nodo con el valor más pequeño que no haya sido asignado previamente
        while (temp != NULL) {
            if (temp->x < min_value && temp->index == -1) {
                min_value = temp->x;
                min_node = temp;
            }
            temp = temp->next;
        }

        // Asigna el índice al nodo con el valor más pequeño
        if (min_node != NULL)
        {
            min_node->index = iterador_indice;
            iterador_indice++;
        }
        
        current = current->next; // Avanzamos al siguiente nodo
    }
}

int main(int argc, char **argv) {

    int alpha = 0;
    int j = 0;
    int i = 1;
    int found_alpha = 0;

    if (argc > 1) {
        
        if (ft_strlen(argv[1]) == 0)
        {
            write(1, "Error\n", 6);
            return 0;
        }
        
        NODE *stackA = malloc(sizeof(NODE));
        NODE *stackB = malloc(sizeof(NODE));

        if (argc == 2)
        {
            j = 0;
            while(argv[1][j] != '\0')
            {
                alpha = ft_isalpha(argv[1][j]);
                if (alpha)
                    break;
                j++;
            }
            if (alpha)
                write(1, "Error\n", 6);
            else
                inicializar_stack(stackA, ft_split(argv[1], ' '), -1);
        }
        else
        {
            // falta implementar control errores de caracteres en argumentos sueltos
            while (argv[i] != NULL)
            {
                j = 0;
                while (argv[i][j] != '\0') {
                    if (ft_isalpha(argv[i][j]))
                    {
                        alpha = 1;
                        break;
                    }
                    j++;
                }
                if (alpha)
                    break;
                i++;
            }
            if (alpha)
                write(1, "Error\n", 6);
            else 
                inicializar_stack(stackA, argv, argc);
        }
        //////////////////////////
        /*  Stack inicializado  */
        //////////////////////////
        if (!alpha) //stack antes de modificarse
        {
            imprime_stack(stackA);
        }

        ///////////////////////////////////////
        /*  Asignarle indices a los numeros  */
        ///////////////////////////////////////

        NODE *curr = stackA;

        while (curr != NULL)
        {
            curr->index = -1;
            curr = curr->next;
        }
        if (!alpha)
        {
            printf("Supuestamente esto ha cambiado y ahora imprime todo -1 \n");
            imprime_stack(stackA);
        }

        asignacion_indices(stackA);
        
        //////////////////////////
        /*  Imprime el stack    */
        //////////////////////////
        if (!alpha)
        {
            printf("Supuestamente esto ha cambiado y ahora imprime los indices\n");
            imprime_stack(stackA);
        }
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}