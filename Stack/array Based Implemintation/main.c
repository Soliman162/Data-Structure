#include "std_types.h"
#include "main.h"

void Init_voidStack( Stack *Copy_ptrStack )
{
    Copy_ptrStack->Top_u8 = 0;
}
u8 Push_u8Stack( Stack_Entry Copy_u8Element , Stack *Copy_ptrStack )
{
    if( !StackisFull( Copy_ptrStack->Top_u8  ) )
    {
        Copy_ptrStack->Stack_arr[Copy_ptrStack->Top_u8++] = Copy_u8Element;
        return 1;
    }
    else
    {
        return 0;
    }
}
u8 POP_u8Stack( Stack_Entry *Copy_ptru8Element , Stack *Copy_ptrStack  )
{
   if( !StackisEmpty( Copy_ptrStack->Top_u8 ) ) 
   {
       *Copy_u8Element = Copy_ptrStack->Stack_arr[--Copy_ptrStack->Top_u8];
       return 1;
   }
   else
   {
       return 0;
   }
}
u8 Stack_u8Top( Stack_Entry *Copy_ptru8Top , Stack *Copy_ptrStack )
{
    if( !StackisEmpty( Copy_ptrStack->Top_u8 ) ) 
   {
       *Copy_ptru8Top = Copy_ptrStack->Stack_arr[Copy_ptrStack->Top_u8-1];
       return 1;
   }
   else
   {
       return 0;
   }
}
u8 Stack_u8Size( Stack *Copy_ptrStack )
{
   return  Copy_ptrStack->Top_u8;
}
void Travers_voidStack( Stack *Copy_ptrStack , void(*Copy_ptrFunc)(Stack_Entry) )
{
    for( u8 i=Copy_ptrStack->Top_u8-1 , i>=0 ,i-- )
    {
        (*Copy_ptrFunc)(Copy_ptrStack->Stack_arr[i]);
    }
}
void Clear_voidStack( Stack *Copy_ptrStack )
{
    Copy_ptrStack->Top_u8 = 0;
}
static u8 StackisFull(  u8 Copy_u8Stack_top )
{
    return Copy_u8Stack_top == MAX_STACK;
}
static u8 StackisEmpty( u8 Copy_u8Stack_top )
{
    return Copy_u8Stack_top == 0;  
}