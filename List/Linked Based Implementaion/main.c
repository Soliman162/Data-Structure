#include <stdlib.h>
#include "std_types.h"
#include "main.h"


void List_voidInit(List *Copy_ptrList)
{
    Copy_ptrList->Head = NULL;
    Copy_ptrList->Size = 0;
}
u8 List_u8Empty(List *Copy_ptrList)
{
    return !(Copy_ptrList->Size);
}
u8 List_u8size(List *Copy_ptrList)
{
    return (Copy_ptrList->Size);
}
void Destroy_voidList(List *Copy_ptrList)
{
    List_Node *Temp ;
    while( Copy_ptrList->Head != NULL )
    {
        Temp = Copy_ptrList->Head;
        Copy_ptrList->Head = Copy_ptrList->Head->Next;
        free(Temp);
    }
    Copy_ptrList->Size = 0;
}
void Traverse_voidList(List *Copy_ptrList, void(*Func)(List_Entry))
{
    List_Node *Temp = Copy_ptrList->Head;
    while( Temp != NULL )
    {
        (*Func)( Temp->Data );
        Temp = Temp->Next;
    }
}
void Insert_voidList(List *Copy_ptrList, List_Entry Copy_Data, u8 Copy_u8Index)
{
    List_Node *New_Node = (List_Node *)malloc(sizeof(List_Node));

    New_Node->Data = Copy_Data;

    if( Copy_u8Index == 0 )
    {
        Copy_ptrList->Head = New_Node;
        New_Node->Next = NULL;
    }else
    {
        List_Node *First_Node = Copy_ptrList->Head;
        u8 Iterator_u8 = 0;

        while ( Iterator_u8 < Copy_u8Index-1 && First_Node !=NULL )
        {
            First_Node = First_Node->Next;
            Iterator_u8++;
        }
        New_Node->Next = First_Node->Next;
        First_Node->Next = New_Node;
    }
    Copy_ptrList->Size++;
}

void Delete_voidList(List *Copy_ptrList, List_Entry *Copy_Data, u8 Copy_u8Index)
{
    u8 Iterator_u8 = 0;
    List_Node *Temp = Copy_ptrList->Head;
    List_Node *Temp_2 ;

    if( Copy_u8Index == 0 )
    {
        *Copy_Data = Copy_ptrList->Head->Data;
        Copy_ptrList->Head = Copy_ptrList->Head->Next;
        free(Temp);
    }else
    {
        while ( Iterator_u8 < Copy_u8Index-1 )
        {
            Temp = Temp->Next;
            Iterator_u8++;
        }
        *Copy_Data = Temp->Next->Data;
        Temp_2 = Temp->Next ;
        Temp->Next = Temp_2->Next;
        free(Temp_2);  
    }
    Copy_ptrList->Size--;
}

void Retrive_voidList_Element(List *Copy_ptrList, List_Entry *Copy_Data, u8 Copy_u8Index)
{
    u8 Iterator_u8 ;
    List_Node *Temp = Copy_ptrList->Head;

    for( Iterator_u8 = 0;Iterator_u8<Copy_u8Index;Iterator_u8++ )
    {
        Temp = Temp->Next;
    }
    *Copy_Data = Temp->Data;
}


void Replace_voidList_Element(List *Copy_ptrList, List_Entry Copy_Data, u8 Copy_u8Index)
{
    u8 Iterator_u8 ;
    List_Node *Temp = Copy_ptrList->Head;

    for( Iterator_u8=0;Iterator_u8<Copy_u8Index;Iterator_u8++)
    {
        Temp = Temp->Next;
    }
    Temp->Data = Copy_Data;
}