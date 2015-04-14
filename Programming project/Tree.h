#ifndef __TREE_H__
#define __THREE_H__

#include "DList.h"

template <class TYPE>
struct tnode
{
	TYPE data;
	tnode* parent;
	DList<tnode<TYPE>> children;

	tnode(TYPE _data)
	{
		data = _data;
	}
};

template <class TYPE>
class Tree
{
	tnode<TYPE>* rootNode;

public:

	void Add(const TYPE& dataGiven)
	{
		tnode<TYPE>* newNode = new tnode<TYPE>(dataGiven);
		rootNode->children.Add(newNode);
		node->parent = root;
	}

	void Add(TYPE dataGiven, tnode<TYPE>* parentGiven)
	{
		tnode<TYPE>* newNode = new tnode<TYPE>(dataGiven);
		parentGiven->children.Add(newNode);
		newNode->parent = parentGiven;
	}
};

#endif //__TREE_H__