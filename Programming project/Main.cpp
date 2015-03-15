#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "globals.cpp"

int main(int argc, char** argv)
{

	SList <int> list;
	list.Add(5);
	list.Add(2);
	int b = list.NodeCounter();

	return 0;
}