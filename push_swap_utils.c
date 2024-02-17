#include    "push_swap.h"

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

void ra(NODE **stack) {
    if (*stack == NULL || (*stack)->next == NULL) {
        // Si la pila está vacía o tiene solo un nodo, no hay nada que hacer
        return;
    }

    NODE *current = *stack;
    NODE *second = (*stack)->next;

    // Recorre la lista enlazada hasta llegar al último nodo
    while (current->next != NULL) {
        current = current->next;
    }

    // Hace que el último nodo apunte al primer nodo
    current->next = *stack;

    // Actualiza el tope de la pila al segundo nodo
    *stack = second;

    // Establece el campo next del nuevo último nodo a NULL
    current->next->next = NULL;
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

    /*node->next = *stackB;
    *stackB = node;*/
}

void pb(NODE** stackA, NODE** stackB)
{
    if (*stackA == NULL) {
        return;
    }
    
    // Crear un nuevo nodo y copiar los datos del nodo superior de stackA
    NODE* nuevo_nodo = malloc(sizeof(NODE));
    nuevo_nodo->index = (*stackA)->index;
    nuevo_nodo->next = NULL;

    // Mover el nodo superior de stackA a stackB
    inserta_arriba(nuevo_nodo, stackB);

    // Eliminar el nodo superior de stackA
    NODE* temp = *stackA;
    *stackA = (*stackA)->next;
    free(temp);
}

void conectar(NODE **stackA, NODE **stackB)
{
    while(*stackB != NULL)
    {
        pb(stackB, stackA);
        printf("\nPb\n");
    }
}

void push(NODE** stackA, NODE** stackB)
{
    if (*stackA == NULL) {
        return;
    }
    NODE* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
}

void rotate(NODE** stack) {
    if (*stack == NULL || (*stack)->next == NULL) {
        return;
    }
    NODE* temp = *stack;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    NODE* lastNode = temp->next;
    temp->next = NULL;
    lastNode->next = *stack;
    *stack = lastNode;
}

NODE* copiar_lista(NODE* head) {
    if (head == NULL) {
        return NULL; // Si la lista está vacía, la copia también estará vacía
    }

    // Creamos el primer nodo de la copia
    NODE* newHead = malloc(sizeof(NODE));
    newHead->index = head->index;
    newHead->x = head->x;
    newHead->next = NULL; // La siguiente se actualizará en la iteración

    // Creamos un puntero para recorrer la lista original
    NODE* currentOriginal = head->next;
    // Creamos un puntero para recorrer la lista copiada
    NODE* currentCopy = newHead;

    // Recorremos la lista original y creamos nodos para la copia
    while (currentOriginal != NULL) {
        NODE* newNode = malloc(sizeof(NODE));
        newNode->index = currentOriginal->index;
        newNode->x = currentOriginal->x;
        newNode->next = NULL;

        // Enlazamos el nuevo nodo al final de la lista copiada
        currentCopy->next = newNode;

        // Avanzamos al siguiente nodo en ambas listas
        currentOriginal = currentOriginal->next;
        currentCopy = currentCopy->next;
    }

    return newHead; // Devolvemos la cabeza de la lista copiada
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


