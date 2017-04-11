#include "stdafx.h"


DoubleLinked_List::DoubleLinked_List()
{
	current_NodeNum = 1;
	MAX_NodeNum = 5;
	headNode = new STRU_doubleLinked_List;
	headNode->Prev = NULL;
	headNode->Next = NULL;
	tailNode = headNode;
	currentPointToNode = headNode;


	//currentPointToNode = NULL;
	//tailNode = NULL;
}


DoubleLinked_List::~DoubleLinked_List()
{
	//STRU_doubleLinked_List* p1;
	//STRU_doubleLinked_List* p2;
	//p1 = headNode;
	//p2 = p1;
	//while (p2->Next != NULL)
	//{
	//	p1 = p2->Next;
	//	delete p2;
	//	p2 = p1;
	//}
	//p1 = p2 = NULL;
}


bool DoubleLinked_List::nodeDelete(struct STRU_doubleLinked_List* node)
{
	node->Prev->Next = node->Next;
	delete node;
	current_NodeNum--;
	return false;
}



bool DoubleLinked_List::nodeAdd(struct STRU_doubleLinked_List* node)
{
	if (current_NodeNum < MAX_NodeNum)
	{
		currentPointToNode->Next = node;
		tailNode->Next = node;
		node->Prev = tailNode;
		current_NodeNum++;
		tailNode = node;
		currentPointToNode = node;
		return true;
	}
	else
	{
		struct STRU_doubleLinked_List* p1;
		p1 = headNode;
		headNode = headNode->Next;
		delete p1;
		tailNode->Next = node;
		node->Prev = tailNode;
		tailNode = node;
		currentPointToNode = node;
		return true;
	}
}
