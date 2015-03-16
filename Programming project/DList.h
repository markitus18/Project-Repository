#include <stdlib.h>
#include <Windows.h>

template <class TYPE>
struct dnode
{
	TYPE atr;
	dnode* previous;
	dnode* next;
};

template <class TYPE>
class DList
{
private:

	dnode<TYPE>* start;
	dnode<TYPE>* end;

public:

	DList()
	{
		start = NULL;
		end = NULL;
	}

	~DList(){ DelList(); }


	int NodeCounter()
	{
		int counter = 0;
		if (start != NULL && end != NULL);
		{
			dnode<TYPE>* tmp = new dnode<TYPE>;
			tmp = start;
			counter = 1;
			while (tmp->next != NULL)
			{
				counter++;
				tmp = tmp->next;
			}
		}
		return counter;
	}

	void Add(TYPE atrToAdd)
	{
		dnode < TYPE > * tmp = new dnode < TYPE > ;
		tmp = start;
		if (start != NULL && end != NULL)
		{
			dnode < TYPE >* dnodeX = new dnode < TYPE > ;

			dnodeX->atr = atrToAdd;
			dnodeX->previous = end;
			dnodeX->next = NULL;
			end->next = dnodeX;
			end = dnodeX;
		}
		else
		{
			dnode < TYPE >* dnodeX = new dnode < TYPE >;
			start = dnodeX;
			end = dnodeX;
			dnodeX->atr = atrToAdd;
			dnodeX->previous = NULL;	
			dnodeX->next = NULL;

		}
	}


	dnode<TYPE>* GetPointer(int dnodeN)
	{
		if (start != NULL && end != NULL)
		{
			int counter = 0;
			dnode<TYPE>* tmp = new dnode<TYPE>;
			tmp = start;
			while (tmp->next != NULL && counter < dnodeN)
			{
				tmp = tmp->next;
				counter++;
			}
			if (counter = dnodeN)
				return tmp;
		}
	}

	void DelNode(dnode<TYPE>* del)
	{

		if (start != NULL && end != NULL)
		{
			if (del != NULL)
			{
				if (del->next != NULL && del->previous != NULL)
				{
					del->next->previous = del->previous;
					del->previous->next = del->next;
				}
				
					end = del->previous;
				if (del->previous != NULL)
					del->previous->next = del->next;
				else
					start = del->next;
			}
		}
	}

	void DelList()
	{
		if (start != NULL && end != NULL)
		{
			dnode < TYPE >* tmp = new dnode < TYPE >;
			dnode< TYPE >* tmp2 = new dnode < TYPE >;
			tmp = start;
			while (tmp->next != NULL)
			{
				tmp2 = tmp;
				tmp = tmp->next;
				delete[] tmp2;
			}
		}
		else delete[] start;
		delete[] end;
	}
};