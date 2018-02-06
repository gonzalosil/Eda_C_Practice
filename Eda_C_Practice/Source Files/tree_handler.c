/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifdef __unix__
#include <malloc.h>
#endif

#include "binary_tree.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


Tree_Node *create_node (int key,void *data)
{
    Tree_Node *node_to_add = (Tree_Node*)malloc (sizeof(Tree_Node));
    node_to_add->key = key;
    node_to_add->data = data;
    node_to_add->left_node = NULL;
    node_to_add->right_node = NULL;
    return node_to_add;
}


bool add_tree_node (Tree_Node **root_node, int key, void *data)
{
    bool error = false;
    if (*root_node == NULL)
        *root_node = create_node(key, data);
        
    else if ((*root_node)->key < key)
        add_tree_node(&(*root_node)->right_node, key, data);
    
    else if ((*root_node)->key > key)
        add_tree_node(&(*root_node)->left_node, key, data);
    else //no puede haber dos key iguales
        error = true;
    return error;
}


unsigned int node_count (Tree_Node *root_node)
{
    if (root_node == NULL)
        return 0;
    
    return (1 + node_count(root_node->left_node) + node_count(root_node->right_node));
}

void transverse_preorder (Tree_Node *root_node)
{
    if (root_node == NULL);
    else 
    {
        visit(root_node);
        transverse_preorder (root_node->left_node);
        transverse_preorder(root_node->right_node);
    }
        
}

void transverse_posorder (Tree_Node *root_node)
{
    if (root_node == NULL);
    
    else
    {
        transverse_posorder(root_node->left_node);
        transverse_posorder(root_node->right_node);
        visit(root_node);
    }
}

void transverse_inorder (Tree_Node *root_node)
{
    if (root_node == NULL);
    
    else
    {
        transverse_inorder(root_node->left_node);
        visit(root_node);
        transverse_inorder(root_node->right_node);
    }
}

bool get_data_search_bst (Tree_Node *root_node, int key, void *data)
{
    bool key_found;
    
    if (root_node == NULL)
        key_found = false;
    
    else if (key < root_node->key)
        key_found = get_data_search_bst(root_node->left_node, key, data);
    
    else if (key > root_node->key)
        key_found = get_data_search_bst(root_node->right_node, key, data);
    else 
    {
        key_found = true;
        data = root_node->data;
    }
    return key_found; 
}


bool set_data_search_bst (Tree_Node *root_node, int key, void *data)
{
    bool key_found;
    
    if (root_node == NULL)
        key_found = false;
    
    else if (key < root_node->key)
        key_found = set_data_search_bst(root_node->left_node, key, data);
    
    else if (key > root_node->key)
        key_found = set_data_search_bst(root_node->right_node, key, data);
    else 
    {
        key_found = true;
        root_node->data = data;
    }
    return key_found; 
}

Tree_Node *get_node (Tree_Node *root_node, int key)
{
    if (root_node == NULL);
    
    else if (key < root_node->key && root_node->left_node != NULL)
        root_node = get_node(root_node->left_node, key);
    
    else if (key > root_node->key && root_node->right_node != NULL)
        root_node = get_node(root_node->right_node, key);
    
    else if (key != root_node->key)
        root_node = NULL;
        
    return root_node; 
}

Tree_Node *remove_tree_node(Tree_Node* root_node, int key)
{
    if (root_node == NULL) //si el arbol esta vacio
        return root_node;
   
    if (key < root_node->key) //si la key recibida es menor se mete a la izquierda
        root_node->left_node = remove_tree_node (root_node->left_node, key);
   
    else if (key > root_node->key) //si la key reccibida es mayor, se mete a la dereha
        root_node->right_node = remove_tree_node(root_node->right_node, key);
   
    else //si el numero es igual
   {
      if (root_node->left_node == NULL) //tiene un hijo o ninguno
      {
          Tree_Node *temp = root_node->right_node;
          free (root_node);
          return temp;
      }
      else if (root_node->right_node == NULL)
      {
          Tree_Node *temp = root_node->left_node;
          free(root_node);
          return temp;
      }
      //si tiene dos hijos
      Tree_Node *temp = get_subroot_min (root_node->right_node);
      root_node->key = temp->key; //copia la informacion del nodo que hay que sacar con el que hay que poner en su lugar
      root_node->data = temp->data;
      root_node->right_node = remove_tree_node(root_node->right_node, temp->key);
   }
    return root_node;
                  
}

Tree_Node *get_subroot_min (Tree_Node *node)
{
    if (node->left_node == NULL)
        return node;
    
    node = get_subroot_min(node->left_node);
    return node;
        
}
void visit(Tree_Node* root_node)
{
    printf("%d\n", root_node->key);
}

void free_tree (Tree_Node *root_node)
{
    if (root_node == NULL);
    
    else
    {
        free_tree(root_node->left_node);
        free_tree(root_node->right_node);
        free(root_node);
    }
}
