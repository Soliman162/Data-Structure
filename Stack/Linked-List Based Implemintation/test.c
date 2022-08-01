#include <stdio.h>
#include "std_types.h"
#include "main.h"
#include "main.c"

void Display_voidElements(Stack_Entry Copy_u8Data);

int main(void)
{
    Stack_Entry X;
    Stack S_1;

    Init_voidStack(&S_1);
    for(u8 i=0;i<=10;i++)
    {
        Push_u8Stack(i,&S_1);
    }
    Travers_voidStack(&S_1,Display_voidElements);
    printf("------------------------------------------------------\n");
    POP_u8Stack(&X,&S_1);
    printf("%d\n",X);

    printf("------------------------------------------------------\n");
    Travers_voidStack(&S_1,Display_voidElements);

    return 0;
}

void Display_voidElements(Stack_Entry Copy_u8Data)
{
    printf("%d\n",Copy_u8Data);
}