/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifdef __unix__
#include <malloc.h>
#endif

#include "queue.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue (Queue *queue)
{
    queue->count=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void enqueue (Queue *queue, void *data)
{
    Queue_Node *queue_to_insert = (Queue_Node*)malloc(sizeof(Queue_Node));
    Queue_Node *temp;
    
    if (!queue->count)//quiere decir que va a ser el primer elemento que se agrega
    {
        queue->head = queue_to_insert;
        queue->tail = queue_to_insert;
        queue_to_insert->data = data;
        queue_to_insert->next = NULL;
    }
    else //si ya hay mas de un elemento
    {
        temp = queue->tail;
        queue->tail = queue_to_insert;
        queue_to_insert->data = data;
        temp->next = queue_to_insert;
    }
    
    queue->count++;
}

void *dequeue (Queue *queue)
{
    Queue_Node *temp = queue->head;
    void *temp_ptr;
    queue->head = temp->next;
    temp_ptr = temp->data;
    free(temp);
    queue->count--;
    return temp_ptr;
}

int is_queue_empty (Queue *queue)
{
    int empty=0;
    
    if (!queue->count)
        empty=1;
    
    return empty;
        
}

void free_queue (Queue *queue)
{
    
    while (!is_queue_empty(queue))
        dequeue(queue);
}
