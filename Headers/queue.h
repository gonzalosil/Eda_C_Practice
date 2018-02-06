/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: parallels
 *
 * Created on February 2, 2018, 12:30 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

struct Queue_Node{
    
    void *data;
    struct Queue_Node *next;
};


struct Queue{
    
    unsigned int count;
    struct Queue_Node *head;
    struct Queue_Node *tail;
};

typedef struct Queue_Node Queue_Node;
typedef struct Queue Queue;


void init_queue (Queue *queue);
void enqueue (Queue *queue, void *data);
void *dequeue (Queue *queue);
int is_queue_empty (Queue *queue);
void free_queue (Queue *queue);

#endif /* QUEUE_H */

