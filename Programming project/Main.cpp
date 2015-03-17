#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"

int main(int argc, char** argv)
{
	DynArray <int> arr(5);
	arr.Reallocate(6);
	arr.PushBack(3);
	arr.Insert(5, 4);
	arr[0] = 1;
	return 0;
}