#pragma once
class ListNode
{
		friend struct SList;
public:
	//ListNode();
	int nData;
private:
	ListNode * pNext, *pPast; //��������� �� ��������� ������� ������
	ListNode() : pPast(nullptr), pNext(nullptr) {};
};
