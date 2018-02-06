/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binary_tree.h
 * Author: parallels
 *
 * Created on February 2, 2018, 11:35 AM
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

struct Tree_Node{
    
    struct Tree_Node *left_node;
    void *data;
    int key;
    struct Tree_Node *right_node;
};

typedef struct Tree_Node Tree_Node;



Tree_Node *create_node (int key, void *data);
bool add_tree_node (Tree_Node **root_node, int key, void *data);
unsigned int node_count(Tree_Node* root_node);
void transverse_preorder (Tree_Node *root_node);
void transverse_posorder (Tree_Node *root_node);
void transverse_inorder (Tree_Node *root_node);
bool get_data_search_bst (Tree_Node *root_node, int key, void *data); //obtiene el ccontenido del arbol
bool set_data_search_bst (Tree_Node *root_node, int key, void *data); //setea el contenido del arbol
Tree_Node *get_node (Tree_Node *root_node, int key); //devuelve NULL si el nodo con esa key no existe
Tree_Node *remove_tree_node (Tree_Node *root_node, int key);
Tree_Node *get_subroot_min (Tree_Node *node);
void visit(Tree_Node *root_node);
void free_tree (Tree_Node *root_node);


#endif /* BINARY_TREE_H */

