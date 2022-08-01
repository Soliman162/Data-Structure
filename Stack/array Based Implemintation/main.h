#ifndef MAIN_H
#define MAIN_H

#define Stack_Entry     u8
#define MAX_STACK 255

typedef struct{

    u8 Top_u8;
    Stack_Entry Stack_arr[MAX_STACK];

}Stack;


void Init_voidStack( Stack *Copy_ptrStack );
u8 Push_u8Stack( Stack_Entry Copy_u8Element , Stack *Copy_ptrStack );
u8 POP_u8Stack( Stack_Entry *Copy_ptru8Element , Stack *Copy_ptrStack  );
u8 Stack_u8Top( Stack_Entry *Copy_ptru8Top , Stack *Copy_ptrStack );
u8 Stack_u8Size( Stack *Copy_ptrStack );
void Clear_voidStack( Stack *Copy_ptrStack );
void Travers_voidStack( Stack *Copy_ptrStack , void(*Copy_ptrFunc)(Stack_Entry) );
static u8 StackisFull( u8 Copy_u8Stack_top  );
static u8 StackisEmpty(u8 Copy_u8Stack_top  );


#endif