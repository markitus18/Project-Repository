/*
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"
#include "Projectile.h"
#include "Point2f.h"
*/
#include "Queue.h"
#include "Tree.h"
#include "Stack.h"

#include <iostream>
int main(int argc, char** argv)
{
	Tree<char> myTree('F');

	treeNode <char>* b = myTree.Add('B');
	treeNode <char>* g = myTree.Add('G');

	myTree.Add('A', b);

	treeNode<char>* d = myTree.Add('D', b);
	myTree.Add('C', d);
	myTree.Add('E', d);

	treeNode<char>* i = myTree.Add('I', g);
	myTree.Add('H', i);

	DList<char>* myList = new DList<char>;



	myTree.VisitAllNodes_PreorderIterative(myList);


	dnode<char>* tmp = new dnode<char>;
	tmp = myList->start;

	for (int i = 0; i < 9; i++)
	{
		std::cout << tmp->atr;
		tmp = tmp->next;
	}

	return 0;
}