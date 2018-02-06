/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifdef __unix__
#include <malloc.h>
#endif

#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void init_list (List* list)
{
    list->count=0;
    list->head=NULL;
}
int add_node (List* list, int position, void* value_of_node)
{
    int error = 0;
    unsigned int i;
    Node *temp_node = list->head;
    Node *node_to_add = (Node*)malloc(sizeof(Node));
    node_to_add->data = value_of_node;
    
    if (position == 1)
    {
        node_to_add->next_node = list->head;
        list->head = node_to_add;
        list->count++;
    }
    else if ( position <= list->count+1  && position > 0)//agrega cuando ya hay un nodo o mas en la lista
    {
        for (i=2; i< position; i++)
            temp_node = temp_node->next_node;
        
        node_to_add->next_node = temp_node->next_node;
        temp_node->next_node = node_to_add;
        list->count++;
        
    }
    else //se mando mal la posicion
    {
        error = 1;
    }
    return error;
}

void print_node_int_data (List* list, int node_to_print)
{
    Node *temp_node = go_to_node(list, node_to_print);;
    printf ("Data from node %d is %d\n",node_to_print, *((int*)temp_node->data));
}

Node* go_to_node (List *list, int node_to_find)
{
    unsigned int i;
    Node *temp_node = list->head;

    if (list->count >= node_to_find)
    {
        for (i=1; i < node_to_find; i++)
            temp_node = temp_node->next_node;
    }
    return temp_node;
}

void remove_node (List *list, int element_to_remove)
{
    Node* temp_node;
    Node* temp_node2;
    
    if (element_to_remove == 1)
    {
        temp_node = go_to_node(list, element_to_remove);
        list->head = temp_node->next_node;
        free(temp_node);
        list->count--;
    }
    else if (element_to_remove <= list->count)
    {
        temp_node = go_to_node(list,element_to_remove);//node to remove
        temp_node2 = go_to_node(list, element_to_remove-1); //find previous node
        temp_node2->next_node = temp_node->next_node;
        free(temp_node);
        list->count--;
    }
    
}

void free_list (List* list)
{
    unsigned int i;
    
    for (i=1; i<=list->count; i++)
        remove_node(list, i);
        
}
