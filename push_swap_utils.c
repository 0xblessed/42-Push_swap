#include    "push_swap.h"
#include    "libft/libft.h"

void establecer_valor_1(NODE **stack)
{
    NODE *curr = *stack;

    while (curr != NULL)
    {
        curr->index = -1;
        curr = curr->next;
    }     
}

void establecer_valor_0(NODE **stack)
{
    NODE *curr = *stack;

    while (curr != NULL)
    {
        curr->x = 0;
        curr = curr->next;
    }     
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nb)
{
	int	i;
	int	num;
	int	signo;

	i = 0;
	num = 0;
	signo = 1;
	while (nb[i] == ' ' || nb[i] == '\r' || nb[i] == '\t'
		|| nb[i] == '\n' || nb[i] == '\v' || nb[i] == '\f')
	{
		i++;
	}
	if (nb[i] == '-')
		signo = signo * -1;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		num = (num * 10) + (nb[i] - '0');
		i++;
	}
	return (num * signo);
}

void imprime_stack(NODE *stackA)
{
    NODE *curr = stackA;

    printf("Stack:\n");
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
            if (temp->x < min_value && temp->index == -1)
            {
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

void inserta_arriba(NODE *node, NODE **stackB)
{
    if (*stackB == NULL)
    {
        *stackB = node;
    }
    else
    {
        node->next = *stackB;
        *stackB = node;
    }
}

void conectar(NODE **stackA, NODE **stackB, int k)
{
    while(*stackB != NULL)
    {
        push(stackB, stackA);
        printf("pb\n");
        printf("%d\n", k);k++;
    }
}

NODE* copiar_lista(NODE* head) {
    if (head == NULL) {
        return NULL;
    }

    NODE* newHead = malloc(sizeof(NODE));
    newHead->index = head->index;
    newHead->x = head->x;
    newHead->next = NULL;

    NODE* currentOriginal = head->next;
    NODE* currentCopy = newHead;

    while (currentOriginal != NULL) {
        NODE* newNode = malloc(sizeof(NODE));
        newNode->index = currentOriginal->index;
        newNode->x = currentOriginal->x;
        newNode->next = NULL;
        currentCopy->next = newNode;
        currentOriginal = currentOriginal->next;
        currentCopy = currentCopy->next;
    }
    return newHead;
}

int isSorted(NODE *stack)
{
    NODE *curr = stack;
    int before = -1;
    while (curr != NULL)
    {
        if(before > curr->index)
        {
            return 0;
        }
        before = curr->index;
        curr = curr->next;
    }
    return 1;
}

int control_errores_string(char **argv)
{
    int j;

    j = 0;
    while(argv[1][j] != '\0')
    {
        if (ft_isalpha(argv[1][j]))
            return (1);
        j++;
    }
    return (0);
}

int control_errores_sueltos(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i] != NULL)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (ft_isalpha(argv[i][j]))
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

// Función para ordenar el stack
void radix_sort(NODE** stackA, NODE** stackB) {
    establecer_valor_1(stackA); // Pasando &stackA para modificar el puntero stackA
    asignacion_indices(*stackA);
    establecer_valor_0(stackA);
    NODE* curr = copiar_lista(*stackA);
    int digito = 0;
    int k = 0;
    
    while (!isSorted(*stackA)) {
        while (curr != NULL) {
            int num = curr->index >> digito & 1;
            if (num == 1) {
                ra(stackA);
                printf("ra\n");
            } else {
                push(stackA, stackB);
                printf("pb\n");
            }
            printf("%d\n", k);
            k++;
            curr = curr->next;
        }
        conectar(stackA, stackB, k);
        digito++;
        curr = copiar_lista(*stackA);
    }
}

/*void	sort_three(NODE **a)
{
	NODE	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}*/