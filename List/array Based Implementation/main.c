#include "std_types.h"
#include "main.h"

void List_voidInit(List *Copy_ptstList)
{
    Copy_ptstList->Size = 0;
}
void List_voidInsert(List *Copy_ptstList,List_Entry Copy_Data,u8 Copy_u8Index )
{
    u8 i ;
    for(i=Copy_ptstList->Size-1;i<=Copy_u8Index;i--)
    {
        Copy_ptstList->Data[i+1] = Copy_ptstList->Data[i];
    }
    Copy_ptstList->Data[Copy_u8Index] = Copy_Data;
    Copy_ptstList->Size++;
}
void List_voidDelete(List *Copy_ptstList,List_Entry *Copy_Data,u8 Copy_u8Index)
{
    u8 i;
    *Copy_Data = Copy_ptstList->Data[Copy_u8Index];
    for(i=Copy_u8Index;i<=Copy_ptstList->Size-1;i++)
    {
        Copy_ptstList->Data[i] = Copy_ptstList->Data[i+1];
    }
    Copy_ptstList->Size--;
}
void List_voidTraverse_List(List *Copy_ptstList,void(*Pf)(List_Entry))
{
    u8 i;
    for( i=0;i<Copy_ptstList->Size;i++)
    {
        (*Pf)(Copy_ptstList->Data[i]);
    }
}
void List_voidReplace(List *Copy_ptstList,u8 Copy_u8Index,List_Entry Copy_Data)
{
    Copy_ptstList->Data[Copy_u8Index] = Copy_Data;
}
void List_voidClear(List *Copy_ptstList)
{
    Copy_ptstList->Size = 0;
}
u8 List_voidSize(List *Copy_ptstList)
{
    return (Copy_ptstList->Size);
}
u8 List_u8Empty(List *Copy_ptstList)
{
    return (!Copy_ptstList->Size);
}
u8 List_u8Full(List *Copy_ptstList)
{
    return (Copy_ptstList->Size == Max_Size);
}