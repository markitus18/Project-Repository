#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "globals.cpp"

int main(int argc, char** argv)
{
	int b;
	
	DList <int> list;
	b = list.NodeCounter();
	list.Add(5);
	list.Add(2);
	b = list.NodeCounter();
	return 0;
}