#include <stdio.h>
#include <stdlib.h>
#include "..\Linked-List Based Implemintation\std_types.h"
#include "..\Linked-List Based Implemintation\main.h"
#include "..\Linked-List Based Implemintation\main.c"


u8 Is_u8Digit(u8 Copy_u8Char);
void Infix_voidToPostFix(u8 Copy_u8InFix[] );
u8 Check_u8Precedent(u8 Copy_u8Operand_1, u8 Copy_u8Operand_2);

void main(void){

    u8 In_u8Fix[] = "1+3*5-2/1*2+8";
    //u8 Post_u8Fix[] = "";
    Infix_voidToPostFix(In_u8Fix);



}

u8 Is_u8Digit(u8 Copy_u8Char)
{
    return(Copy_u8Char>='0' && Copy_u8Char<='9');
}
u8 Check_u8Precedent(u8 Copy_u8Operand_1, u8 Copy_u8Operand_2)
{
    if(Copy_u8Operand_1=='$') 
    {
        return 1;
    }
    if((Copy_u8Operand_1=='*') || (Copy_u8Operand_1=='/')) 
    {
        return (Copy_u8Operand_2 != '$');
    }
    if((Copy_u8Operand_1 == '+') || (Copy_u8Operand_1 == '-'))
    {
        return ( (Copy_u8Operand_2!='$') && (Copy_u8Operand_2!='*') && (Copy_u8Operand_2!='/') );
    }
    return 0;
}
void Infix_voidToPostFix(u8 Copy_u8InFix[] )
{
    u8 i,j;
    u8 Char_u8;
    u8 Copy_u8PostFix[] = "          " ;
    u8 Stack_u8Top_Value;
    Stack Operators;
    Init_voidStack(&Operators);
    for(i=0,j=0; (Char_u8=Copy_u8InFix[i])!='\0' ; i++ )
    {
        if( Is_u8Digit(Char_u8) )
        {
            Copy_u8PostFix[j++] = Char_u8;
        }else
        {
            if( !StackisEmpty( &Operators ) )
            {
                Stack_u8Top(&Stack_u8Top_Value,&Operators);
                while( !StackisEmpty( &Operators ) && Check_u8Precedent(Stack_u8Top_Value,Char_u8) )
                {
                    POP_u8Stack( &Stack_u8Top_Value ,&Operators);
                    Copy_u8PostFix[j++] = Stack_u8Top_Value;
                    if(!StackisEmpty( &Operators )){ Stack_u8Top(&Stack_u8Top_Value,&Operators); }
                }
            }
            Push_u8Stack(Char_u8,&Operators);
        }
    }
    while( !StackisEmpty( &Operators ) )
    {
        POP_u8Stack(&Stack_u8Top_Value,&Operators);
        Copy_u8PostFix[j++] = Stack_u8Top_Value;
    }
    Copy_u8PostFix[j] = '\0';

    printf("%s",Copy_u8PostFix);
}
