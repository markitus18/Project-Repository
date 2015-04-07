#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <assert.h>
#include "globals.h"

#define BLOCK_SIZE 16

template <class DATA>
class Queue
{
private:

	DATA* data;
	unsigned int allocatedMemory;
	unsigned int numElements;
	unsigned int startingPosition;

public:

	////////////////
	//Constructors//
	////////////////

	Queue()
	{
		data = new DATA[BLOCK_SIZE];
		allocatedMemory = BLOCK_SIZE + 1;
		numElements = 0;
	}


	///////////////
	//Destructor//
	///////////////

	~Queue()
	{
		delete[] data;
	}

	///////////////////
	//Data Management//
	///////////////////

	void PushBack(DATA value) //afegir un valor al final
	{
		if (numElements + 1 >= allocatedMemory)
			Reallocate(allocatedMemory + BLOCK_SIZE);
		numElements++;
		data[(startingPosition + numElements) - 1] = value;
	}

	DATA Pop() //esborra l'ultim valor
	{
		if (numElements > 0)
		{
			DATA value = data[startingPosition];
			numElements--;
			startingPosition++;
			allocatedMemory--;
			return value;
		}
	}

	const DATA Pick(unsigned int position) const
	{
		assert(position < numElements);
		return data[position+startingPosition];
	}


private:

	void Reallocate(const unsigned int newMemorySize)
	{

		if (startingPosition >= BLOCK_SIZE)
		{
			for (unsigned int i = 0; i < (allocatedMemory - startingPosition); i++)
			{
				data[i] = data[startingPosition + i];
			}
			startingPosition = 0;
		}
		else
		{
			DATA* newData = new DATA[allocatedMemory + BLOCK_SIZE];

			allocatedMemory += BLOCK_SIZE;

			for (unsigned int i = 0; i < allocatedMemory; i++)
			{
				newData[i] = data[i];
			}

			delete[]data;
			data = new DATA[allocatedMemory];
			data = newData;
		}

	}

};

#endif //__QUEUE_H__