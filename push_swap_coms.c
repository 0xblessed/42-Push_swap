#include    "push_swap.h"
#include    "libft/libft.h"

void ra(NODE **stack)
{
    NODE *current = *stack;
    NODE *second = (*stack)->next;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = *stack;
    *stack = second;
    current->next->next = NULL;
}

void push(NODE** stackA, NODE** stackB)
{
    NODE* temp = *stackA;
    
    if (*stackA == NULL)
        return;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
}