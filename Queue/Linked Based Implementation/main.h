#ifndef MAIN_H
#define MAIN_H

typedef u8 Queue_Entry

typedef struct queue_node{

    Queue_Entry Data;
    struct queue_node *next;

}Queue_Node;


typedef struct queue{

    Queue_Node Front;
    Queue_Node Rear;
    u8 Size;

}Queue;

void Queue_voidInit(Queue *Copy_Queue);
void Queue_voidAppend(Queue *Copy_Queue,Queue_Entry Copy_Element);
void Queue_voidServe(Queue *Copy_Queue , Queue_Entry *Save_Element );
void Queue_voidTravers_Queue(Queue *Copy_Queue , void(*pf)(Queue_Entry) );
u8 Queue_u8Size(Queue *Copy_Queue);
u8 Queue_u8Empty(Queue *Copy_Queue);
u8 Queue_u8Full(Queue *Copy_Queue);
void Queue_voidCear(Queue *Copy_Queue);


#endif