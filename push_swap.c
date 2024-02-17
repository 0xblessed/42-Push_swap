#include    "push_swap.h"
#include    "libft/libft.h"


int main(int argc, char **argv) {

    int alpha = 0;
    int j = 0;
    int i = 1;
    int found_alpha = 0;

    if (argc > 1)
    {
        
        if (ft_strlen(argv[1]) == 0)
        {
            write(1, "Error\n", 6);
            return 0;
        }
        
        NODE *stackA = malloc(sizeof(NODE));
        NODE *stackB = NULL; //malloc(sizeof(NODE));

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
        if (alpha) //stack antes de modificarse
        {
            return 0;
        }
        printf("\nStackA\n");
        imprime_stack(stackA);
        printf("\nStackB\n");
        imprime_stack(stackB);

        establecer_valor_1(&stackA);

        printf("Todos los indices son -1\n");

        imprime_stack(stackA);

        printf("Asignamos todos los indices y el valor 0\n");

        asignacion_indices(stackA);

        establecer_valor_0(&stackA);
        
        imprime_stack(stackA);

        NODE *curr = malloc(sizeof(NODE));
        
        curr=copiar_lista(stackA);

        int digito = 0;

        printf("\n\t\t EMPEZAMOS BUCLE \t\t\n");
        int sorted = isSorted(stackA);
        int k = 0;
        while(sorted == 0)
        {
            while (curr != NULL)
            {
                int num = curr->index>>digito & 1;
                if(num == 1)
                {
                    ra(&stackA);
                    printf("\nRa\n");
                }
                else
                {
                    push(&stackA, &stackB);
                    printf("\nPb\n");
                }
                curr = curr->next;
            }
            conectar(&stackA, &stackB);
            sorted = isSorted(stackA);
            digito++;
            curr=copiar_lista(stackA);
        }
        /*while (curr != NULL)
        {
                int num = curr->index>>digito & 1;
                if(num == 1)
                {
                    ra(&stackA);
                    printf("%d\n", (curr->index>>digito & 1));
                    printf("\nRa\n");

                    printf("MIRAMOS SI HA HECHO EL RA BIEN\n");
                    printf("StackA :\n");imprime_stack(stackA);
                    printf("StackB :\n");imprime_stack(stackB);
                }
                else
                {
                    push(&stackA, &stackB);
                    printf("\nPb\n");
                    printf("MIRAMOS SI HA HECHO EL PB BIEN\n");
                    printf("StackA :\n");imprime_stack(stackA);
                    printf("StackB :\n");imprime_stack(stackB);
                }
                printf("%d\n", k);k++;
                curr = curr->next;
        }
            conectar(&stackA, &stackB);
            printf("MIRAMOS SI STACK ESTA CONECTADO\n");
            imprime_stack(stackA);
            imprime_stack(stackB);
            printf("MIRAMOS SI STACK ESTA SORTED\n");
            sorted = isSorted(stackA);
            printf("\t\t%d\t\t", sorted);
            digito++;printf("DIGITO : %d", digito);

            curr=copiar_lista(stackA);
            printf("ACTUALIZAMOS CURR PARA QUE TENGA EL STACK A DE NUEVO\n");
            imprime_stack(curr);
            
        
        printf("OPAOPAOPAOPAOPAOPAOA\n\n");*/
        printf("\nStackA\n");
        imprime_stack(stackA);
        printf("\nStackB\n");
        imprime_stack(stackB);
    } 
    else 
        write(1, "Error\n", 6);

    return 0;
}