#include <stdio.h>
#include "std_types.h"
#include "main.h"
#include "main.c"

void Display_voidElements(List_Entry Copy_u8Data);


int main (void)
{
    List_Entry X;
    List l1;
    List_voidInit(&l1);
    for(u8 i=0;i<=10;i++)
    {
        Insert_voidList(&l1,i,i);
    }

    Traverse_voidList(&l1,Display_voidElements);

    Replace_voidList_Element(&l1,100,5);
    printf("------------------------------------------------------------\n");

    Traverse_voidList(&l1,Display_voidElements);

    printf("------------------------------------------------------------\n");

    Delete_voidList(&l1,&X,5);

    Traverse_voidList(&l1,Display_voidElements);
    printf("------------------------------------------------------------\n");

    printf("%d\n",X);

    return 0;
}

void Display_voidElements(List_Entry Copy_u8Data)
{
    printf("%d\n",Copy_u8Data);
}