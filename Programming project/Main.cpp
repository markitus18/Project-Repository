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
	arr.PushBack(1);
	arr.Insert(5, 1);
	arr[0] = 3;
	return 0;
}