#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"


int main(int argc, char** argv)
{
	DynArray<int> array;

	for (int i = 0; i < 16; ++i)
	{
		array.PushBack(i);
	}

	array.Insert(999, 3);
	array.Insert(888, 5);
	array.Insert(777, 8);
}