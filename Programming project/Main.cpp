#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"
#include "Projectile.h"
#include "Point2f.h"

#include "Queue.h"
#include "Tree.h"
#include "Stack.h"

#include <iostream>
int main(int argc, char** argv)
{
/*
	Tree<char> myTree('F');

	treeNode <char>* b = myTree.Add('B');
	treeNode <char>* g = myTree.Add('G');

	myTree.Add('A', b);

	treeNode<char>* d = myTree.Add('D', b);
	myTree.Add('C', d);
	myTree.Add('E', d);

	treeNode<char>* i = myTree.Add('I', g);
	myTree.Add('H', i);
*/
	

	Tree<char> myTree('1');

	treeNode <char>* dos = myTree.Add('2');
	treeNode <char>* tres = myTree.Add('3');
	treeNode <char>* quatre = myTree.Add('4');

	myTree.Add('5', dos);
	myTree.Add('6', dos);

	myTree.Add('7', tres);

	myTree.Add('8', quatre);
	myTree.Add('9', quatre);
	myTree.Add('a', quatre);


	DList<char>* myList_PreorderRecursive = new DList<char>;
	DList<char>* myList_InorderRecursive = new DList<char>;
	DList<char>* myList_PostorderRecursive = new DList<char>;
	DList<char>* myList_PreorderIterative = new DList<char>;
	DList<char>* myList_InorderIterative = new DList<char>;
	DList<char>* myList_PostorderIterative = new DList<char>;


	myTree.PreorderRecursive(myList_PreorderRecursive);
	myTree.InorderRecursive(myList_InorderRecursive);
	myTree.PostorderRecursive(myList_PostorderRecursive);
	myTree.PreorderIterative(myList_PreorderIterative);
	myTree.InorderIterative(myList_InorderIterative);
	myTree.PostorderIterative(myList_PostorderIterative);


	dnode<char>* tmp = new dnode<char>;

	std::cout << "Preorder              1 2 5 6 3 7 4 8 9 a" << std::endl << std::endl;

	tmp = myList_PreorderRecursive->start;
	std::cout << "Preorder Recursive    ";

	for (int i = 0; i < myList_PreorderRecursive->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl << std::endl;

	tmp = myList_PreorderIterative->start;
	std::cout << "Preorder Iterative    ";

	for (int i = 0; i < myList_PreorderIterative->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Inorder(rounded down) 5 2 6 1 3 7 8 4 9 a" << std::endl << std::endl;

	tmp = myList_InorderRecursive->start;
	std::cout << "Inorder Recursive     ";

	for (int i = 0; i < myList_InorderRecursive->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl << std::endl;

	
	tmp = myList_InorderIterative->start;
	std::cout << "Inorder Iterative     ";
	
	for (int i = 0; i < myList_InorderIterative->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}
	
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Postorder             5 6 2 7 3 8 9 a 4 1" << std::endl << std::endl;

	tmp = myList_PostorderRecursive->start;
	std::cout << "Postorder Recursive:  ";

	for (int i = 0; i < myList_PostorderRecursive->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl << std::endl;


	tmp = myList_PostorderIterative->start;
	std::cout << "Postorder Iterative   ";

	for (int i = 0; i < myList_PostorderIterative->NodeCounter(); i++)
	{
		std::cout << tmp->atr << " ";
		tmp = tmp->next;
	}

	std::cout << std::endl << std::endl;

	system("pause");

	return 0;
}