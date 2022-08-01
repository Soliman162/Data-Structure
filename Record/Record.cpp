#include <iostream>
#include <stdlib.h>
#include "std_types.h"
#include "main.hpp"

using namespace std;


Rec_Node::Rec_Node():next(NULL)
{
	
}

Record::Record()
{
	Head = NULL;
	Size = 0;
}
void Record::Add_voidElement(Record_Entry Copy_Data, u16 Copy_u16ID)
{
		Copy_u16ID = Record::Uniq_voidID(Copy_u16ID);
		Rec_Node *New_Node = (Rec_Node *)malloc(sizeof(Rec_Node));
		
		New_Node->Data = Copy_Data;
		New_Node->ID_u16 = Copy_u16ID;
		
		if( Head == NULL )
		{
			Head = New_Node;

		}else
		{
			Rec_Node *temp = Head;

			while( temp->next != NULL )
			{
				temp = temp->next;
			}
			temp->next = New_Node;
		}

		New_Node->next = NULL; 
		Size++;
}

void Record::Delete_voidElement(u16 Copy_u16ID)
{
	Rec_Node *temp = Head;
	if( temp->ID_u16 == Copy_u16ID )
	{
		Head = Head->next;
		free(temp);
		
	}else
	{
		Rec_Node *temp_2 ;
		do
		{
			
			if( temp->next->ID_u16 != Copy_u16ID )
			{
				temp_2 = temp->next;
				temp->next = temp->next->next;
				free(temp_2);
				cout<<"Element is deleted\n";
				Size--;
				break;
			}
			else if( temp->next == NULL )
			{
				cout<<"ID is not exist.";
				break;
			}
			temp=temp->next;

		}while(temp != NULL);
	}
}
void Record::GET_voidData(u16 Copy_u16ID, Record_Entry *Copy_ptrData)
{
		Rec_Node *temp = Head;
		while( temp != NULL )
		{
			if(temp->ID_u16 == Copy_u16ID)
			{
				*Copy_ptrData = temp->Data;
				cout<<"Data is Captured.\n";
				break;
			}
			temp = temp->next;
		}
		if( temp == NULL )
		{
			cout<<"ID is not exist.\n";
		}
}
u16 Record::Uniq_voidID(u16 Copy_ID)
{
		Rec_Node *temp = Head;
		while( temp!=NULL )
		{
			if( temp->ID_u16 == Copy_ID )
			{
				cout<<"ID is Reserved,try again\n";
				cout<<"please enter ID:";
				cin>>Copy_ID;
				temp = Head;
				continue;
			}
			temp = temp->next;
		}
		return Copy_ID;
}
void Record::Traverse_voidRecord(void(*func)(Record_Entry))
{
		Rec_Node *temp = Head;
		
		while(temp != NULL)
		{
			(*func)(temp->Data);
			temp = temp->next;
		}
}

void Record::Clear_voidRecord(void)
{
		Rec_Node *temp = Head;
		
		while(temp!=NULL)
		{
			Head = Head->next;
			free(temp);
			temp = Head;
		}
		Size = 0;
}


