/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifdef __unix__
#include <malloc.h>
#endif

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


void init_stack (Stack* stack)
{
    stack->last_in = NULL;
}

void push (Stack *stack, void* data)
{
    Stack *stack_to_push = (Stack*) malloc(sizeof(Stack));
    stack_to_push->last_in = stack->last_in;
    stack_to_push->data = data;
    stack->last_in = stack_to_push;
}

void* pop (Stack *stack)
{
    void *temp_ptr;
    if (!is_stack_empty(stack))
    {
        Stack *temp = stack->last_in;
        stack->last_in = temp->last_in;
        temp_ptr = temp->data;
        free(temp);
        return temp_ptr;
    }
    else return NULL;
}

int is_stack_empty (Stack *stack)
{
    int empty=0;
    
    if (stack->last_in == NULL)
        empty=1;
    
    return empty;
}

void free_stack (Stack *stack)
{
    while (!is_stack_empty(stack))
    {
        pop(stack);
    }
}
