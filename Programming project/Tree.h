#ifndef __TREE_H__
#define __THREE_H__

#include "DList.h"

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

	void VisitAllNodes_PreorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_PreorderRecursive(list);
	}

	void VisitAllNodes_PostorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_PostorderRecursive(list);
	}

	void VisitAllNodes_InorderRecursive(DList<DATA>* list) const
	{
		rootNode->VisitAll_InorderRecursive(list);
	}


};

#endif //__TREE_H__