#include <stdlib.h>

#include "std_types.h"
#include "main.h" 


void Queue_voidInit(Queue *Copy_Queue)
{
    Copy_Queue->Front = NULL;
    Copy_Queue->Rear = NULL;
    Copy_Queue->Size = 0;
}
void Queue_voidAppend(Queue *Copy_Queue,Queue_Entry Copy_Element)
{
    Queue_Node  *New_Node = (*Queue_Node) malloc(sizeof(Queue_Node));
    New_Node->Data = Copy_Element;
    New_Node->next = NULL ;

    if(!Copy_Queue->Front)
        Copy_Queue->Front = New_Node;
    else
        Copy_Queue->Rear->next = New_Node;
    Copy_Queue->Rear = New_Node;
    Copy_Queue->Size++;
}
void Queue_voidServe(Queue *Copy_Queue , Queue_Entry *Save_Element )
{
    Queue_Node  *Temp = Copy_Queue->Front ;
    *Save_Element = Copy_Queue->Front->Data;
    Copy_Queue->Front = Copy_Queue->Front->next;
    free(Temp);
    if(!Copy_Queue->Front)
        Copy_Queue->rear = NULL;
    Copy_Queue->Size--;
}
void Queue_voidTravers_Queue(Queue *Copy_Queue , void(*pf)(Queue_Entry) )
{
    Queue_Node  *Temp  ;
    for(Temp = Copy_Queue->Front;Temp;Temp=Temp->next )
        (*pf)(Temp->Data);

}
u8 Queue_u8Size(Queue *Copy_Queue)
{
    return Copy_Queue->Size;
}
u8 Queue_u8Empty(Queue *Copy_Queue)
{
    return (!Copy_Queue->Size);
}
u8 Queue_u8Full(Queue *Copy_Queue)
{
    return 0;
}
void Queue_voidCear(Queue *Copy_Queue)
{
    while(Copy_Queue->Front)
    {
        Copy_Queue->Rear = Copy_Queue->Front->next;
        free(Copy_Queue->Front);
        Copy_Queue->Front = Copy_Queue->Rear;
    }
    Copy_Queue->Size = 0;
}