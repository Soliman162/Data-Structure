#ifndef MAIN_H
#define MAIN_H

typedef u8 Stack_Entry ;

typedef struct Stack_node{

    Stack_Entry Data_u8;
    struct Stack_node *Next;

}Stack_Node;

typedef struct stack{

    Stack_Node *Top ;
    u8 Stack_Size;

}Stack;


void Init_voidStack( Stack *Copy_ptrStack );
void Push_u8Stack( Stack_Entry Copy_u8Element , Stack *Copy_ptrStack );
void POP_u8Stack( Stack_Entry *Copy_ptru8Element , Stack *Copy_ptrStack  );
void Stack_u8Top( Stack_Entry *Copy_ptru8Top , Stack *Copy_ptrStack );
u8 Stack_u8Size( Stack *Copy_ptrStack );
void Clear_voidStack( Stack *Copy_ptrStack );
void Travers_voidStack( Stack *Copy_ptrStack , void(*Copy_ptrFunc)(Stack_Entry) );
u8 StackisFull( u8 Copy_u8Stack_top  );
u8 StackisEmpty(Stack *Copy_u8Stack_top  );


#endif