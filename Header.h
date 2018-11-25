#include <iostream>

#include "ListNode.h"

struct SList //��������� ������
{
	ListNode *pRoot, *pTail; //��������� �� ������ ������� ������ � �� ��� �����
	int size;
public:
	SList() :pRoot(nullptr), pTail(nullptr), size(0) {}; //�������� ������ � �����
	void pushFront(const int _nData,const int a); //������� ���������� �������� � ������
	int popFront(const int a); //������� �������� �������� ������
	void printList(const int a); //����� �������� ������
	~SList();
};

SList::~SList() { //����������
	ListNode *pTemp;
	while (pRoot != nullptr) {
		pTemp = pRoot;
		pRoot = pRoot->pNext;
		delete pTemp;
	}
	while (pTail != nullptr) {
		pTemp = pTail;
		pTail = pTail->pPast;
		delete pTemp;

	}
}


void SList::printList(const int a) //������� ������
{
	if (pRoot == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return; //����� ������ ����� ���������� ������� �� ���� �������
	}
	if (pTail == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return; //����� ������ ����� ���������� ������� �� ���� �������
	}
	if (a == 1)
		{ //����������� ������ ������
			ListNode *pIt = pRoot;
			while (pIt != nullptr)
				{
					std::cout << " " << pIt->nData;
					pIt = pIt->pNext;
				}
			std::cout << std::endl;
		}
	if (a == 2) 
		{//����������� ����� �������
			ListNode *pIt = pTail;
			while (pIt != nullptr)
				{
					std::cout << " " << pIt->nData;
					pIt = pIt->pPast;
				}
		std::cout << std::endl;
	}
}


void SList::pushFront(const int _nData,const int a) //������� ���������� ���������
{
	if (a == 1) //���������� �������� �����
		{

			ListNode *pLeft = new ListNode;		//��������� ������ ��� ����� ������� ���������
			pLeft->pPast = nullptr;
			pLeft->nData = _nData;				//���������� �������� � ���������
			pLeft->pNext = pRoot;				//��������� ����� �� ��������� ������� ������
			if (pRoot != nullptr) { pRoot->pPast = pLeft;}
			if (size == 0) { pRoot = pTail = pLeft;}
			else { pRoot = pLeft; }
			size++;
		}

	if (a == 2) // ���������� �������� ������
		{
			ListNode *pRight = new ListNode;
			pRight->pNext=nullptr;
			pRight->nData = _nData;
			pRight->pPast = pTail;
			if (pTail != nullptr) {pTail->pNext = pRight;}
			if (size == 0) {pRoot = pTail = pRight;}
			else {pTail = pRight;}
			size++;

		}

}

int SList::popFront(const int a)
{
	if (a == 1) {
		ListNode *pTemp = pRoot;
		if (pRoot->pNext == nullptr) 
			{
				pRoot = nullptr;
				pTail = nullptr;
			}
		else{
				pRoot = pRoot->pNext;
				pRoot->pPast = nullptr;
		}
		delete pTemp;
		size--;

	}
	if (a == 2) {
		ListNode *pTemp = pTail;
		if (pTail->pPast == nullptr)
			{
				pTail = nullptr;
				pRoot = nullptr;
			}
		else 
			{
				pTail = pTail->pPast;
				pTail->pNext = nullptr;
		}
						delete pTemp;
		size--;

	}

	return 0;
}
#pragma once
