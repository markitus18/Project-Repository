#ifndef __DLIST_H__
#define __DLIST_H__

#include <stdlib.h>
#include <Windows.h>
#include <assert.h>

#include "Globals.h"


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
public:

	dnode<TYPE>* start;
	dnode<TYPE>* end;

public:

	DList()
	{
		start = NULL;
		end = NULL;
	}

	~DList(){ DelList(); }


	unsigned int NodeCounter()
	{
		int counter = 0;
		if (start != NULL && end != NULL)
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
 		dnode < TYPE >* dnodeX = new dnode < TYPE >;

		if (start != NULL && end != NULL)
		{
			end->next = dnodeX;
		}
		else
		{
			start = dnodeX;
		}
		dnodeX->previous = end;
		dnodeX->next = NULL;
		end = dnodeX;
		dnodeX->atr = atrToAdd;
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
			if (counter == dnodeN)
				return tmp;
		}
	}

	void DelNode(dnode<TYPE>* del)
	{
		if (del != NULL && start != NULL && end != NULL)
		{
			if (del->previous != NULL)
			{
				del->previous->next = del->next;
			}
			else
				start = del->next;
			if (del->next != NULL)
			{
				del->next->previous = del->previous;
			}
			else
				end = del->previous;
		}
	}

	unsigned int DelNodes(const int position, const int nodes)
	{
		if (start != NULL && end != NULL)
		{
			if (position < NodeCounter())
			{
				int counter;
				for (counter = 0; counter < MIN(nodes, NodeCounter()); counter++)
				{
					DelNode(GetPointer(position + counter));
				}
				return counter + 1;
			}

		}
		return 0;
	}

	void DelList()
	{
		while (start != NULL && end != NULL)
		{		
			end = start;
			start = start->next;
			delete[]end;
		}
		end = start;
	}

	TYPE& operator[] (unsigned int index)
	{
		if (start != NULL && end != NULL)
		{
			int counter = 0;
			dnode<TYPE>* tmp = new dnode<TYPE>;
			tmp = start;
			while (tmp->next != NULL && counter < index)
			{
				tmp = tmp->next;
				counter++;
			}
			if (counter == index)
				return tmp->atr;
			else
				assert(1 == 2);
		}
	}

	const TYPE& operator[] (unsigned int index) const
	{
		if (start != NULL && end != NULL)
		{
			int counter = 0;
			dnode<TYPE>* tmp = new dnode<TYPE>;
			tmp = start;
			while (tmp->next != NULL && counter < index)
			{
				tmp = tmp->next;
				counter++;
			}
			if (counter == index)
				return tmp->atr;
			else
				assert(1 == 2);
		}
	}

	int BubbleSort()
	{
		int itinerations = 0;
		bool swap = true;

		while (swap == true)
		{
			swap = false;
			dnode<TYPE>* tmp = new dnode <TYPE>;
			tmp = start;
			while (tmp != NULL && tmp->next != NULL)
			{
				itinerations++;
				if (tmp->atr > tmp->next->atr)
				{
					/*
					if (tmp->next->next != NULL)
						tmp->next->next->previous = tmp;
					if (tmp->previous != NULL)
					tmp->previous->next = tmp->next;

					tmp->next->previous = tmp->previous;
					tmp->previous = tmp->next;

					tmp->next = tmp->previous->next;
					tmp->previous->next = tmp;
					*/
					SwapNodes(tmp, tmp->next);
					swap = true;
				}
				tmp = tmp->next;
			}
		}
		return itinerations;
	}

	void SwapNodes(dnode<TYPE>* node1, dnode<TYPE>* node2)
	{
		dnode<TYPE>* tmp;
		if (node1->previous)
			node1->previous->next = node2;
		if (node2->next)
			node2->next->previous = node1;
		tmp = node2->next;
		node2->next = node1->next;
		node1->next = tmp;
		tmp = node2->previous;
		node2->previous = node1->previous;
		node1->previous = tmp;

		node1->previous->next = node1;
		node2->next->previous = node2;
	}
};
#endif //__SLIST_H__