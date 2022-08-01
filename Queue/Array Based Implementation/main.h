#ifndef MAIN_H
#define MAIN_H

typedef u8 Queue_Entry;


#define MAX_QUEUE   100


typedef struct{

    u8 Front;
    u8 Rear;
    Queue_Entry Entry[MAX_QUEUE] ;
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