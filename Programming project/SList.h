#include <stdlib.h>
#include <Windows.h>

template <class TYPE>
struct snode
{
	TYPE atr;
	snode* next;
};

template <class TYPE>
class SList
{
private:

	snode<TYPE>* start;

public:
	
	SList()
	{
		start = NULL;
	}

	~SList(){ DelList(); }


	int NodeCounter()
	{
		int counter = 0;
		if (start != NULL)
		{
			snode<TYPE>* tmp = new snode<TYPE>;
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
		snode<TYPE>* tmp = new snode<TYPE>;
		tmp = start;
		if (start != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}

		}	
		snode<TYPE>* snodeX = new snode < TYPE > ;
		if (start != NULL)
			tmp->next = snodeX;
		else
			start = snodeX;
		snodeX->atr = atrToAdd;
		snodeX->next = NULL;			
	}


	snode<TYPE>* GetPointer(int snodeN)
	{
		if (start != NULL)
		{
			int counter = 0;
			snode<TYPE>* tmp = new snode<TYPE>;
			tmp = start;
			while (tmp->next != NULL && counter < snodeN)
			{
				tmp = tmp->next;
				counter++;
			}
			if (counter = snodeN)
				return tmp;
		}
	}

	void DelNode(snode<TYPE>* del)
	{				

		if (start != NULL)
		{
			if (del != NULL)
			{	

				snode<TYPE>* tmp = new snode < TYPE > ;
				tmp = start;
				while (tmp->next != NULL && tmp->next != del)
				{
					tmp = tmp->next;
				}
				tmp->next = del->next;
			}
		}
	}

	void DelList()
	{
		if (start != NULL)
		{
			snode < TYPE >* tmp = new snode < TYPE > ;
			snode< TYPE >* tmp2 = new snode < TYPE > ;
			tmp = start;
			while (tmp->next != NULL)
			{
				tmp2 = tmp;
				tmp = tmp->next;
				delete[] tmp2;
			}
		}
		else delete[] start;
	}
};