#ifndef MAIN_H
#define MAIN_H


typedef u8 List_Entry;

#efine Max_Size 25


typedef struct {

    List_Entry Data[Max_Size];
    u8 Size;

}List;


void List_voidInit(List *Copy_ptstList);
void List_voidInsert(List *Copy_ptstList,List_Entry Copy_Data,u8 Copy_u8Index );
void List_voidDelete(List *Copy_ptstList,List_Entry *Copy_Data,u8 Copy_u8Index);
void List_voidTraverse_List(List *Copy_ptstList,void(*Pf)(List_Entry));
void List_voidReplace(List *Copy_ptstList,u8 Copy_u8Index,List_Entry Copy_Data);
void List_voidClear(List *Copy_ptstList);
u8 List_voidSize(List *Copy_ptstList);
u8 List_u8Empty(List *Copy_ptstList);
u8 List_u8Full(List *Copy_ptstList);

#endif 