#ifndef MAIN_H  
#define MAIN_H

 typedef u8 List_Entry ;

typedef struct list_node{

    List_Entry Data;
    struct list_node *Next;

}List_Node;

typedef struct list{

    List_Node *Head;
    u8 Size;

}List;

void List_voidInit(List *Copy_ptrList);
u8 List_u8Empty(List *Copy_ptrList);
u8 List_u8size(List *Copy_ptrList);
void Destroy_voidList(List *Copy_ptrList);
void Traverse_voidList(List *Copy_ptrList, void(*Func)(List_Entry));
void Insert_voidList(List *Copy_ptrList, List_Entry Copy_Data, u8 Copy_u8Index);
void Delete_voidList(List *Copy_ptrList, List_Entry *Copy_Data, u8 Copy_u8Index);
void Retrive_voidList_Element(List *Copy_ptrList, List_Entry *Copy_Data, u8 Copy_u8Index);
void Replace_voidList_Element(List *Copy_ptrList, List_Entry Copy_Data, u8 Copy_u8Index);

#endif