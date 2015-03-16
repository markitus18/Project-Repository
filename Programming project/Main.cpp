#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "globals.cpp"

int main(int argc, char** argv)
{
	int b = 0;
	
	DList <int> list;
	list.Add(5);
//	list.Add(4);
	list.Add(6);
	list.DelNode(list.GetPointer(0));
	b = list.NodeCounter();
	return 0;
}