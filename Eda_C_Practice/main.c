/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: parallels
 *
 * Created on February 1, 2018, 6:27 PM
 */

#ifdef __unix__
#include <malloc.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"
#include <stdlib.h>

#warning "tengo que hacer cola circular"

/*
 *
 */
int main(void) {
    
    List list;
    Stack stack;
    Queue queue;
    Tree_Node *root_node;
    unsigned int i;
    int hola[11];
    void *data = NULL;
    
    for (i=0; i<11; i++)
        hola[i]=i;

    init_list(&list);
    init_stack(&stack);
    init_queue(&queue);
    root_node = create_node(12, data);
    
    
    free_tree(root_node);
    free_list(&list);
    free_stack(&stack);
    free_queue(&queue);
    
    return (EXIT_SUCCESS);
}
