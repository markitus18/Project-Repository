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

	DynArray()
	{
		data = NULL;
		allocatedMemory = 0;
		numElements = 0;
	}

	DynArray(const unsigned int size)
	{
		allocatedMemory = size + 1;
		data = new TYPE[allocatedMemory];
		numElements = 0;
	}

	~DynArray()
	{
		if (data != NULL)
		{
			delete[] data;
		}
	}

	void Reallocate(const unsigned int newMemorySize)
	{
		if (data != NULL)
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
	}

	void PushBack(const int value) //afegir un valor al final
	{
		if (data != NULL)
		{
			if (numElements + 1 == allocatedMemory)
			{
				Reallocate(allocatedMemory + 1);
			}
			else
			{
				numElements++;
			}
			data[numElements-1] = value;
		}
	}

	int Pop() //esborra l'ultim valor
	{
		numElements--;
	}

	void Insert(const int value, const unsigned int position) //afegir un valor a la posicio X
	{
		if (data!= NULL)
		{
			if (position > allocatedMemory - 1)
			{
				Reallocate(position + 1);
			}
			if (numElements + 1 < allocatedMemory)
			{
				TYPE* newData = new TYPE[numElements + 2];
				newData = data;
				for (int i = 0; i < position; i++)
				{
					data[i] = newData[i];
				}
				data[position] = value;
				for (int i = position+1; i < numElements + 1; i++)
				{
					data[i] = newData[i - 1];
				}
			}
		}
	}

	int& operator[](const unsigned int index) //retorna el valor de la posicio index, amb una referència per poder modificar-la
	{
		assert(index < numElements);
		return data[index];
	}

	const int& operator[](const unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}
};


#endif