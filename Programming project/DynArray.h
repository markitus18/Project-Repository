#ifndef __DynArray_H__
#define __DynArray_H__

#include <stdlib.h>
#include <assert.h>
#include "globals.h"

template <class TYPE>
class DynArray
{
private:

	TYPE* data;
	unsigned int allocatedMemory;
	unsigned int numElements;


public:

	////////////////
	//Constructors//
	////////////////

	DynArray()
	{
		data = NULL;
		allocatedMemory = 0;
		numElements = 0;
	}

	DynArray(const unsigned int size)
	{
		allocatedMemory = size;
		data = new TYPE[allocatedMemory];
		numElements = 0;
	}


	///////////////
	//Destructor//
	///////////////

	~DynArray()
	{
			delete[] data;
	}


	///////////////////
	//Data Management//
	///////////////////

	void PushBack(const TYPE value) //afegir un valor al final
	{

		if (numElements >= allocatedMemory)
			Reallocate(allocatedMemory + 1);

		numElements++;
		data[numElements-1] = value;
	}

	bool Pop() //esborra l'ultim valor
	{
		if (numElements > 0)
		{
			numElements--;
			return true;
		}
		else
			return false;
	}

	bool Insert(const TYPE value, const unsigned int position) //afegir un valor a la posicio X
	{
		if (position > numElements)
		{
			return false;
		}

		if (position == numElements)
		{
			PushBack(value);
			return true;
		}

		if (numElements + 1 > allocatedMemory)
			Reallocate(allocatedMemory + 1);

		for (unsigned int i = numElements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = value;
		numElements++;
	}

	TYPE* At(const unsigned int index)
	{
		TYPE* atr = NULL;
		if (index < numElements)
		{
			return atr = &data[index];
		}
		return atr;
	}

	const TYPE* At(const unsigned int index) const
	{
		TYPE* atr = NULL;
		if (index < numElements)
		{
			return atr = &data[index];
		}
		return atr;
	}

	void Clear()
	{
		numElements = 0;
	}

	int BubbleSort_i()
	{
		bool swap = true;
		int counter = 0;

		while (swap == true)
		{
			swap = false;
			for (int i = 0; i < (GetSize() - 1); i++)
			{
				counter++;
				if (data[i] > data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					swap = true;
				}
			}
		}
		return counter;
	}

	// Casa: "algoritmo definitivo": comsort -> gap: distància entre els dos numeros que s'estan comparant
	//											agafa el gap amb la distància d'un 97% i el redueix a 1 a cada iteració.
	unsigned int BubbleSort()
	{
		bool swap = true;
		int counter = 0;

		int lastItem = GetSize() - 1;
		int lastItem_tmp = lastItem;

		int firstItem = 0;
		int firstItem_tmp = firstItem;
		while (swap == true)
		{
			swap = false;

			for (int i = firstItem; i < lastItem; i++)
			{
				counter++;
				if (data[i] > data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					swap = true;
					lastItem_tmp = i;
				}
			}

			lastItem = lastItem_tmp;
			for (int i = lastItem; i > firstItem; i--)
			{
				counter++;
				if (data[i] < data[i - 1])
				{
					Swap(data[i], data[i - 1]);
					swap = true;
					firstItem_tmp = i;
				}
			}
			firstItem = firstItem_tmp;
		}
		return counter;
	}

	unsigned int CombSort()
	{
		bool change = true;
		int gap = numElements - 1;
		unsigned int counter = 0;
		while (gap > 1 || change == true)
		{
			gap /= 1.3;
			if (gap < 1)
				gap = 1;
			change = false;
			for (int i = 0; i + gap < numElements; i++)
			{
				counter++;
				if (data[i]>data[i + gap])
				{
					Swap(data[i], data[i + gap]);
					change = true;
				}
			}
		}
		return counter;
	}
	/////////////
	//Operators//
	/////////////

	TYPE& operator[](const unsigned int index) //retorna el valor de la posicio index, amb una referència per poder modificar-la
	{
		assert(index < numElements);
		return data[index];
	}

	const TYPE& operator[](const unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}


	/////////
	//Utils//
	/////////

	unsigned int GetCapacity()
	{
		return allocatedMemory;
	}

	unsigned int GetSize()
	{
		return numElements;
	}

	unsigned int removeWastedMemory()
	{
		if (numElements == allocatedMemory)
		{
			return 0;
		}

		int toRemove = allocatedMemory - numElements;
		TYPE* newData = new TYPE[numElements];
		for (int i = 0; i < numElements; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		allocatedMemory = numElements;
		data = new TYPE[allocatedMemory];
		data = newData;

		return toRemove;
	}

private:
		
	void Reallocate(const unsigned int newMemorySize)
	{
		TYPE* newData = new TYPE[newMemorySize];

		for (int i = 0; i < MIN(newMemorySize, allocatedMemory); i++)
		{
			newData[i] = data[i];
		}

		delete[]data;
		allocatedMemory = newMemorySize;
		data = new TYPE[allocatedMemory];
		data = newData;

		if (numElements >= allocatedMemory)
		{
			numElements = allocatedMemory - 1;
		}
	}
};


#endif