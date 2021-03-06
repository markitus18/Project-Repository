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
#include "Circle.h"

#include <iostream>


int Fib(int position)
{
	int result = 1;
	for (int i = 0, p = i; i < position; ++i, result += p, p = result - p)
	return result;
}


int main(int argc, char** argv)
{
	

	/*
	String a("holaa holaa");
//	a.DeleteSpaces();
	a.Substitute("holaa", "adeu");

	std::cout << (a.str) << std::endl;
	/*
	DList<int> myList;
	for (int i = 0; i < 6; i++)
	{
		myList.Add(i);
	}
	myList.SwapNodes(myList.GetPointer(2), myList.GetPointer(3));

	/*
	DList <int> myList;
	for (int i = 0; i < 9000; i++)
	{
		myList.Add(rand());
	}

	int b = myList.BubbleSort();

	int a = 0;
	for (int i = 0; i < 9000; i++)
	{
		a = myList[i];
		std::cout << a << " ";
	}


	/*
	DList<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.Add(i);
	}

	int b = myList[9];
	std::cout << b;
	
	
	
	/*
	String a ("   hola     ");
	a.Trim();

	for (int i = 0; i < a.GetLenght(); i++)
	{
		std::cout << a.str[i];
	}
	std::cout << std::endl;
	/*
	Circle <int> a(5, 3, 2);
	Circle <int> b(1, 2, 2);

	bool intersect = a.Intersect(b);

	if (intersect)
		printf("true");
	else
		printf("false");

	/*
	DynArray<int> array;

	for (int i = 10000; i > 0; i--)
	{
		array.PushBack(rand());
	}

	int iterations_i = 0;
	int iterations = 0;


	iterations = array.BubbleSort();
	
	for (int i = 0; i < 10000; i++)
	{
		std::cout<< array[i]<<" ";
	}
	
	std::cout<<std::endl<<(iterations)<<std::endl;
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

	

	Tree<char> myTree('1');

	treeNode <char>* dos = myTree.Add('2');
	treeNode <char>* tres = myTree.Add('3');
	treeNode <char>* quatre = myTree.Add('4');
	
	myTree.Clear();

	int b = 5;

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

	*/
	system("pause");

	return 0;
}