#include <stdlib.h>
#include <Windows.h>

template <class TYPE>
struct node
{
	TYPE atr;
	node* next;
};

template <class TYPE>
class SList
{
private:

	node<TYPE>* start;

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
			node<TYPE>* tmp = new node<TYPE>;
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
		node<TYPE>* tmp = new node<TYPE>;
		tmp = start;
		if (start != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}

		}	
		node<TYPE>* nodeX = new node < TYPE > ;
		if (start != NULL)
			tmp->next = nodeX;
		else
			start = nodeX;
		nodeX->atr = atrToAdd;
		nodeX->next = NULL;			
	}


	node<TYPE>* GetPointer(int nodeN)
	{
		if (start != NULL)
		{
			int counter = 0;
			node<TYPE>* tmp = new node<TYPE>;
			tmp = start;
			while (tmp->next != NULL && counter < nodeN)
			{
				tmp = tmp->next;
				counter++;
			}
			if (counter = nodeN)
				return tmp;
		}
	}

	void DelNode(node<TYPE>* del)
	{				

		if (start != NULL)
		{
			if (del != NULL)
			{	

				node<TYPE>* tmp = new node < TYPE > ;
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
			node < TYPE >* tmp = new node < TYPE > ;
			node< TYPE >* tmp2 = new node < TYPE > ;
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