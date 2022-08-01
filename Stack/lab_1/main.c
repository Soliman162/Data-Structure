#include <stdio.h>
#include "..\Linked-List Based Implemintation\std_types.h"

void move_Disks(u8 Elements_num, u8 *Copy_u8arr_1,u8 *Copy_u8arr_2, u8 *Copy_u8Temp);

void main(void)
{
    u8 Arr_1[5] = {1,2,3,4,5};
    u8 Arr_2[5] = {0};
    u8 Arr_3[5] = {0};

    move_Disks(5,Arr_1,Arr_2,Arr_3);

    for(u8 i=0;i<5;i++)
    {
        printf("%d\n",Arr_2[i]);
    }
}

void move_Disks(u8 Elements_num, u8 *Copy_u8arr_1,u8 *Copy_u8arr_2, u8 *Copy_u8Temp)
{ 
    u8 i = 0;
    u8 Count_u8 = 0;
    while( Elements_num>0)
    {
        for(i = 1;i<Elements_num;i++)
        {
            Copy_u8Temp[i-1] = Copy_u8arr_1[i]  ;
            Copy_u8arr_1[i] = 0;
        }

        Copy_u8arr_2[Count_u8++] = Copy_u8arr_1[0] ;
        Elements_num--;

        for(i = 0;i<Elements_num;i++)
        {
            Copy_u8arr_1[i] = Copy_u8Temp[i] ;
            Copy_u8Temp[i] = 0;
        }
    }
}