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
		allocatedMemory = size + 1;
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
		if (numElements + 1 == allocatedMemory)
		{
			Reallocate(allocatedMemory + 1);
		}
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

		if (numElements + 1 == allocatedMemory)
		{
			Reallocate(allocatedMemory + 1);
			TYPE* newData = new TYPE[numElements + 2];

			for (int i = 0; i <= numElements; i++)
			{
				newData[i] = data[i];
			}

			data[position] = value;
			numElements++;
			for (int i = position+1; i < numElements + 1; i++)
			{
				data[i] = newData[i - 1];
			}

		}
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


	/////////////
	//Operators//
	/////////////

	TYPE& operator[](const unsigned int index) //retorna el valor de la posicio index, amb una referčncia per poder modificar-la
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

	int GetCapacity()
	{
		return allocatedMemory;
	}

	int GetSize()
	{
		return numElements;
	}

private:
		
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
};


#endif