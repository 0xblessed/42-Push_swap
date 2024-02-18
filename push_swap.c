#include    "push_swap.h"
#include    "libft/libft.h"


int main(int argc, char **argv)
{
    int alpha = 0;
    int j = 0;
    int i = 1;

    if (argc > 1)
    {
        NODE *stackA = malloc(sizeof(NODE));
        NODE *stackB = NULL;

        if (ft_strlen(argv[1]) == 0)
        {
            write(1, "Error\n", 6);
            return 0;
        }
        if (argc == 2)
        {
            if (control_errores_string(argv))
            {
                write(1, "Error\n", 6);
                return 0;
            }  
            else
                inicializar_stack(stackA, ft_split(argv[1], ' '), -1);
        }
        else
        {
            if (control_errores_sueltos(argv))
            {
                write(1, "Error\n", 6);
                return 0;
            }
            else 
                inicializar_stack(stackA, argv, argc);
        }
        radix_sort(&stackA, &stackB);
    }
    else 
    {
        write(1, "Error\n", 6);
    }
    return 0;
}
