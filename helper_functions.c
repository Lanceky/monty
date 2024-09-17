#include "monty.h"

/**
 * is_number - checks if a string is a valid integer
 * @str: string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_number(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

/**
 * add_node - adds a new node at the beginning of a stack_t stack
 * @stack: double pointer to the top of the stack
 * @n: value to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;

    return new_node;
}

/**
 * add_node_end - adds a new node at the end of a stack_t stack
 * @stack: double pointer to the top of the stack
 * @n: value to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node_end(stack_t **stack, const int n)
{
    stack_t *new_node, *temp;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        new_node->prev = NULL;
        *stack = new_node;
    }
    else
    {
        temp = *stack;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }

    return new_node;
}
