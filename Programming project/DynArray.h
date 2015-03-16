#ifndef __DynArray_H__
#define __DynArray_H__

#include <stdlib.h>
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
		numElements = size;
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
			delete[] data;
			numElements = 0;
			allocatedMemory = newMemorySize;
			data = new TYPE[allocatedMemory];
		}
	}

	void PushBack(const int value) //afegir un valor al final
	{
		if (data != NULL)
		{
			TYPE* newData = new TYPE;
			newData = data;
			delete[] data;
			numElements++;
			allocatedMemory++;
			newData[numElements] = value;
			data = newData;
		}
	}

	int Pop(); //esborra l'ultim valor

	void Insert(const int value, const unsigned int position); //afegir un valor a la posicio X

	int& operator[](const unsigned int index); //retorna el valor de la posicio index, amb una referència per poder modificar-la

	const int& operator[](const unsigned int index) const;
};


#endif