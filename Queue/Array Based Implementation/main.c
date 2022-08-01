#include "std_types.h"
#include "main.h"



void Queue_voidInit(Queue *Copy_Queue)
{
    Copy_Queue->Front=0;
    Copy_Queue->Rear = -1;
    Copy_Queue->Size = 0;
}
void Queue_voidAppend(Queue *Copy_Queue,Queue_Entry Copy_Element)
{
    Copy_Queue->Rear = (Copy_Queue->Rear+1) % MAX_QUEUE ;
    Copy_Queue->Entry[Copy_Queue->Rear] = Copy_Element;
    Copy_Queue->Size++;
}
void Queue_voidServe(Queue *Copy_Queue , Queue_Entry *Save_Element )
{
    *Save_Element = Copy_Queue->Entry[Copy_Queue->Front];
    Copy_Queue->Front = (Copy_Queue->Front+1) % MAX_QUEUE;
    Copy_Queue->Size--;
}
void Queue_voidTravers_Queue(Queue *Copy_Queue , void(*pf)(Queue_Entry) )
{
    u8 S=0;
    for( POS = Copy_Queue->Front, S = 0;S<Copy_Queue->Size; S++ )
    {
        (*pf)(Copy_Queue->Entry[POS]);
        POS = (POS+1) % MAX_QUEUE;
    }

}
u8 Queue_u8Size(Queue *Copy_Queue)
{
    return (Copy_Queue->Size);
}
u8 Queue_u8Empty(Queue *Copy_Queue)
{
    return (!Copy_Queue->Size);
}
u8 Queue_u8Full(Queue *Copy_Queue)
{
    return (Copy_Queue->Size == MAX_QUEUE);
}
void Queue_voidCear(Queue *Copy_Queue)
{
    Copy_Queue->Front=0;
    Copy_Queue->Rear = -1;
    Copy_Queue->Size = 0;
}