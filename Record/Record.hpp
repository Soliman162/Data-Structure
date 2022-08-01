#ifndef MAIN_HPP
#define MAIN_HPP

//template <class T>

#define Record_Entry u8

class Rec_Node
{
	public:
		Record_Entry Data;
		u16 ID_u16;
		Rec_Node *next;
		Rec_Node();
};


class Record
{
	private:
	
		Rec_Node  *Head;
		u16 Size;
		u16  Uniq_voidID(u16 Copy_ID);
	
	public:
	
		Record();
		void Add_voidElement(Record_Entry Copy_Data, u16 Copy_u16ID);
		void Delete_voidElement(u16 Copy_u16ID);
		void GET_voidData(u16 Copy_u16ID, Record_Entry *Copy_ptrData);
		void Clear_voidRecord(void);
		void Traverse_voidRecord(void(*func)(Record_Entry));	
};


#endif
