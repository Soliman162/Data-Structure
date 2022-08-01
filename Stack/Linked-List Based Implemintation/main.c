#include "stdlib.h"
#include "std_types.h"

#include "main.h"

void Init_voidStack( Stack *Copy_ptrStack )
{
    Copy_ptrStack->Top = NULL; 
    Copy_ptrStack->Stack_Size = 0;
}
void Push_u8Stack( Stack_Entry Copy_u8Element , Stack *Copy_ptrStack )
{
    Stack_Node *Element = (Stack_Node *)malloc(sizeof(Stack_Node));
    Element->Data_u8 = Copy_u8Element;
    Element->Next = Copy_ptrStack->Top;
    Copy_ptrStack->Top = Element;
    Copy_ptrStack->Stack_Size++;
}
void POP_u8Stack( Stack_Entry *Copy_ptru8Element , Stack *Copy_ptrStack  )
{
    Stack_Node *Temp = Copy_ptrStack->Top;
    *Copy_ptru8Element = Temp->Data_u8;
    Copy_ptrStack->Top = Temp->Next;
    free(Temp);
    Copy_ptrStack->Stack_Size--;
}
void Stack_u8Top( Stack_Entry *Copy_ptru8Top , Stack *Copy_ptrStack )
{
    *Copy_ptru8Top = (Copy_ptrStack->Top)->Data_u8;
}
u8 Stack_u8Size( Stack *Copy_ptrStack )
{
    return Copy_ptrStack->Stack_Size;
}
void Clear_voidStack( Stack *Copy_ptrStack )
{
    Stack_Node *Temp = Copy_ptrStack->Top;
    while ( Temp != NULL )
    {
        Copy_ptrStack->Top = Temp->Next;
        free(Temp);
        Temp = Copy_ptrStack->Top;
    }
    Copy_ptrStack->Stack_Size = 0;
}
void Travers_voidStack( Stack *Copy_ptrStack , void(*Copy_ptrFunc)(Stack_Entry) )
{
    Stack_Node *Temp = Copy_ptrStack->Top;
    while( Temp != NULL)
    {
        (*Copy_ptrFunc)(Temp->Data_u8);
        Temp = Temp->Next;
    }

}
u8 StackisFull( u8 Copy_u8Stack_top  )
{
    return 0;
}
u8 StackisEmpty(Stack  *Copy_u8Stack_top  )
{
    return Copy_u8Stack_top->Top == NULL;
}