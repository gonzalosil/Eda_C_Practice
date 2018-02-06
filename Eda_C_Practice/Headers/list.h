/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: parallels
 *
 * Created on February 1, 2018, 6:27 PM
 */

#ifndef LIST_H
#define LIST_H


struct Node{ //nodo
    
    void *data;
    struct Node *next_node;
    
    
};



struct List{
    
    struct Node *head;
    int count;
};

typedef struct Node Node;
typedef struct List List;

void init_list (List* list);
int add_node (List* list, int position, void *value_of_node); //position starts from 1
void print_node_int_data (List* list, int node_to_print);//node to print starts from 1
Node* go_to_node (List *list, int node_to_find); //node to find starts from 1
void remove_node (List *list, int element_to_remove);
void free_list (List *list);

#endif /* LIST_H */

