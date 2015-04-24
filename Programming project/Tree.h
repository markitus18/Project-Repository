#ifndef __TREE_H__
#define __THREE_H__

#include "DList.h"
#include "Stack.h"

///Balanced Tree: de cada node en surten dos->cerques més òptimes dintre dels arbres



//crear "VisitAllNodes" en recursiu i iteratiu, en tots els tipus d'ordre; en iteratiu s'utilitza una pila de crides
template <class DATA>
struct treeNode
{
	DATA data;
	treeNode* parent;
	DList<treeNode<DATA>*> children;

	treeNode(DATA _data)
	{
		data = _data;
	}

	void VisitAll_PreorderRecursive(DList<DATA>* list)
	{
		list->Add(data);
		for (unsigned int i = 0; i < children.NodeCounter(); i++)
		children.GetPointer(i)->atr->VisitAll_PreorderRecursive(list);
	}

	void VisitAll_PostorderRecursive(DList<DATA>* list)
	{

		for (unsigned int i = 0; i < children.NodeCounter(); i++)
			children.GetPointer(i)->atr->VisitAll_PostorderRecursive(list);
		list->Add(data);
	}

	void VisitAll_InorderRecursive(DList<DATA>* list)
	{
		for (unsigned int i = 0; i < children.NodeCounter()/2; i++)
			children.GetPointer(i)->atr->VisitAll_InorderRecursive(list);
		list->Add(data);
		for (unsigned int i = children.NodeCounter() / 2; i < (children.NodeCounter()); i++)
			children.GetPointer(i)->atr->VisitAll_InorderRecursive(list);
	}
};

template <class DATA>
class Tree
{
private:
	treeNode<DATA>* rootNode;

public:

	///////////////
	//Constructor//
	///////////////

	Tree(const DATA& dataGiven)
	{
		rootNode = new treeNode<DATA>(dataGiven);
		rootNode->data = dataGiven;
		rootNode->parent = NULL;
	}

	treeNode<DATA>* Add(const DATA& dataGiven)
	{
		treeNode<DATA>* newNode = new treeNode<DATA>(dataGiven);
		rootNode->children.Add(newNode);
		newNode->parent = rootNode;
		return newNode;
	}

	treeNode<DATA>* Add(DATA dataGiven, treeNode<DATA>* parentGiven)
	{
		treeNode<DATA>* newNode = new treeNode<DATA>(dataGiven);
		parentGiven->children.Add(newNode);
		newNode->parent = parentGiven;
		return newNode;
	}

	//Cerca "Pre-Order: pares->fills"  F B A D C E G I H
	//		"In-Order:	meitat fills->pare->meitat fill	A B C D E F H I G	
	//		"Post-Order: fills->pare"	A C E D B H I G F
	
	//Recursive functions
	void PreorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_PreorderRecursive(list);
	}

	void PostorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_PostorderRecursive(list);
	}

	void InorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_InorderRecursive(list);
	}

	//Iterative functions
	void PreorderIterative(DList<DATA>* list) const
	{
		Stack<treeNode<DATA>*> newStack;
		treeNode<DATA>* newNode = rootNode;
		int i = 0;
		while (newNode)
		{
			list->Add(newNode->data);
			for (int i = newNode->children.NodeCounter(); i > 0; i--)
			{
				newStack.Push(newNode->children.GetPointer(i-1)->atr);
			}
			newNode = newStack.Pop();
		//	i++;
		}
	}

	void PostorderIterative(DList<DATA>* list) const
	{

	}

	void InorderIterative(DList<DATA>* list) const
	{

	}


};

#endif //__TREE_H__