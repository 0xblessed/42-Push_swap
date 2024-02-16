#include    "push_swap.h"
#include    "libft/libft.h"

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
        //////////////////////////
        /*  Stack inicializado  */
        //////////////////////////
        if (!alpha) //stack antes de modificarse
        {
            printf("\nStackA\n");
            imprime_stack(stackA);
            printf("\nStackB\n");
            imprime_stack(stackB);
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
            //printf("Supuestamente esto ha cambiado y ahora imprime todo -1 \n");
            //imprime_stack(stackA);
        }

        asignacion_indices(stackA);
        
        ///////////////////////////////////////////////////////////////////////

        curr = stackA; //conseguimos el indice más alto
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        int size_stack = curr->index;
        int i = 0;
        int digito = 0;
        /*
        curr = stackA;
        printf("ayiyiyi");imprime_stack(curr); printf("ayiyiyi\n\n");
        while(curr != NULL)
        {
            if (((curr->index>>digito)&1) == 1)
            {
                pb(&stackA, &stackB);printf("\n\t\t\tPB\t\t\t\n");
            }
            else
            {
                ra(&stackA);printf("\n\t\t\tRA\t\t\t\n");
            }
            curr = curr->next;
        }
        printf("\n\n OPA OPA\n\n");
            printf("\nStackA\n");
            imprime_stack(stackA);
            printf("\nStackB\n");
            imprime_stack(stackB);
        printf("\n\n OPA OPA\n\n");
        //conectar(&stackA, &stackB);
        //digito++;*/
        

        curr = stackA;

        printf("ayiyiyi");
        imprime_stack(curr);
        printf("ayiyiyi\n\n");
        
        int num = 0;
        while(curr != NULL)
        {
            num = (curr->index>>digito);
            if ((num&1) == 1)
            {
                pb(&stackA, &stackB);
                printf("\nStackA\n");
                imprime_stack(stackA);
                printf("\nStackB\n");
                imprime_stack(stackB);
                printf("\n\t\t\tPB\t\t\t\n");
            }
            else
            {
                ra(&stackA);
                printf("\n\t\t\tRA\t\t\t\n");
            }
            curr = curr->next;
        }


        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////
        /*  Imprime el stack    */
        //////////////////////////
        if (!alpha)
        {
            printf("Supuestamente esto ha cambiado y ahora imprime los indices\n");
            printf("\nStackA\n");
            imprime_stack(stackA);
            printf("\nStackB\n");
            imprime_stack(stackB);
        }
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}