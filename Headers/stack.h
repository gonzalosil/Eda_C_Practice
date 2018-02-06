/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: parallels
 *
 * Created on February 1, 2018, 10:15 PM
 */

#ifndef STACK_H
#define STACK_H


struct Stack{
    
    void* data;
    struct Stack *last_in;
};

typedef struct Stack Stack;

void init_stack (Stack* stack);
void push (Stack *stack, void* data);
void* pop (Stack *stack);//before calling this function you have to check if stack is empty
int is_stack_empty (Stack *stack); //if its empty returns 1 if not returns 0
void free_stack (Stack *stack);
#endif /* STACK_H */

