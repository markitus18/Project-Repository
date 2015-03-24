#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"

#include <iostream>

int main(int argc, char** argv)
{
	DynArray <int> arr(5);
	arr.Reallocate(4);
	arr.PushBack(1);
	arr.PushBack(2);
	arr.PushBack(3);
	arr.Insert(5, 4);
//	arr[0] = 3;



	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i];
	}
	return 0;
}