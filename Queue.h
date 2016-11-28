#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "stdlib.h"
#include "stdio.h"
#include "types.h"

#define MAX_SIZE    100

typedef struct node{

    void *pData;
    struct node* next;
}tstQueueNode;

typedef struct queue{
    
    uint8 size;
    tstQueueNode *head;
    tstQueueNode *tail;
    
}tstQueue;

/*  Function    prototypes  */

//Creates an empty queue
tstQueue* CreateQueue(void);

//Adds an element at the end of the queue
void Enqueue(tstQueue *q, void *pData);

//Deletes and Returns first element of the queue.
void* Dequeue(tstQueue *q);

//Returns the first element of the queue
void* Peek(tstQueue *q);

#endif //_QUEUE_H_
