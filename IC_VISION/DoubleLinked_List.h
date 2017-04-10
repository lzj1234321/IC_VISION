#pragma once
class DoubleLinked_List
{
public:
	struct STRU_doubleLinked_List* headNode;
	struct STRU_doubleLinked_List* tailNode;
	struct STRU_doubleLinked_List* currentPointToNode;
	INT current_NodeNum;
	INT MAX_NodeNum;

	DoubleLinked_List();
	virtual ~DoubleLinked_List();
	bool nodeDelete(struct STRU_doubleLinked_List*);
	bool nodeAdd(struct STRU_doubleLinked_List* node);
};

