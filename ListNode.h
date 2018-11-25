#pragma once
class ListNode
{
		friend struct SList;
public:
	//ListNode();
	int nData;
private:
	ListNode * pNext, *pPast; //”казатель на следующий элемент списка
	ListNode() : pPast(nullptr), pNext(nullptr) {};
};
