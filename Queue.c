#include "Queue.h"

void printQueue(tstQueue *q){
    tstQueueNode *tmp=q->head;

    while(tmp != NULL_PTR){

        printf("|%i| ", *( (uint8*)(tmp->pData) ) );
        tmp=tmp->next;
    }
    printf("\n");

}   
/*
void main(void){
    
    uint8 a,b,c,d,e,f,g,tmp1,tmp2;
    tstQueue *q_u8;

    a=10;
    b=23;
    c=30;
    d=85;
    e=90;
    f=134;
    g=200;

    q_u8=CreateQueue();
    
    Enqueue(q_u8,&b);    
    printQueue(q_u8);
    
    Enqueue(q_u8,&d);    
    printQueue(q_u8);
    
    Enqueue(q_u8,&f);    
    printQueue(q_u8);
    
    Enqueue(q_u8,&g);    
    printQueue(q_u8);
    
    tmp1= *( (uint8*)Dequeue(q_u8) );
    printQueue(q_u8);
 
    tmp2= *( (uint8*)Dequeue(q_u8) );
    printQueue(q_u8);
    
    printf("Sum trial is:%i",tmp1+tmp2);
    Enqueue(q_u8,&e);    
    printQueue(q_u8);
    
    Dequeue(q_u8);
    printQueue(q_u8);
 
    Enqueue(q_u8,&a);    
    printQueue(q_u8);

    Dequeue(q_u8);
    printQueue(q_u8);
    
    Dequeue(q_u8);
    printQueue(q_u8);
 
    Enqueue(q_u8,&c);    
    printQueue(q_u8);
    
    Dequeue(q_u8);
    printQueue(q_u8);
    
    Dequeue(q_u8);
    printQueue(q_u8);
 
    Dequeue(q_u8);
    printQueue(q_u8);

   
}
*/

tstQueue* CreateQueue(void){

    tstQueue *tmp=malloc(sizeof(tstQueue));
    
    if(tmp==NULL_PTR) exit(0);

    tmp->size=0;
    tmp->head=tmp->tail=NULL_PTR;

    printf("Queue created\n");
    return tmp;
}

void Enqueue(tstQueue *q, void *pData){


    tstQueueNode *tmp = malloc(sizeof(tstQueueNode));
    
    if(tmp==NULL_PTR) exit(0);

    tmp->pData=pData;
    tmp->next=NULL_PTR;

    if(q->size) (q->tail)->next = tmp;
    q->tail=tmp;

    //if queue was empty, head and tail are equal.
    if(q->size==0) q->head=tmp;

    q->size++;
    
    printf("Element with add: %x enqueued.\n",pData);
}

void* Dequeue(tstQueue *q){

    tstQueueNode *tmp;
    void *pData;

    if(q->size==0){
        printf("Queue is empty\n\n");
        return NULL_PTR;
    }
    tmp = (q->head);
    q->head = tmp->next;
    q->size--;

    pData=tmp->pData;

    free(tmp);

    printf("Element with add: %x dequeued.\n",pData);
    
    return pData;
}

void* Peek(tstQueue *q){

    return (q->head)->pData;

}
