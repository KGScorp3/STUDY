#include <iostream>

#include "ListNode.h"

struct SList //Структура списка
{
	ListNode *pRoot, *pTail; //Указатель на первый элемент списка и на его конец
	int size;
public:
	SList() :pRoot(nullptr), pTail(nullptr), size(0) {}; //Зануляем начало и конец
	void pushFront(const int _nData,const int a); //функция добавления элемента в список
	int popFront(const int a); //функция удаления элемента списка
	void printList(const int a); //вывод элемента списка
	~SList();
};

SList::~SList() { //Деструктор
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


void SList::printList(const int a) //Фукнция вывода
{
	if (pRoot == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return; //Пишем ретурн чтобы остановить функцию на этом моменте
	}
	if (pTail == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return; //Пишем ретурн чтобы остановить функцию на этом моменте
	}
	if (a == 1)
		{ //Отображение справа налево
			ListNode *pIt = pRoot;
			while (pIt != nullptr)
				{
					std::cout << " " << pIt->nData;
					pIt = pIt->pNext;
				}
			std::cout << std::endl;
		}
	if (a == 2) 
		{//Отображение слева направо
			ListNode *pIt = pTail;
			while (pIt != nullptr)
				{
					std::cout << " " << pIt->nData;
					pIt = pIt->pPast;
				}
		std::cout << std::endl;
	}
}


void SList::pushFront(const int _nData,const int a) //Функция добавления элементов
{
	if (a == 1) //Добавление элемента слева
		{

			ListNode *pLeft = new ListNode;		//Выделение памяти под новый элемент структуры
			pLeft->pPast = nullptr;
			pLeft->nData = _nData;				//Записываем значение в структуру
			pLeft->pNext = pRoot;				//Указываем адрес на следующий элемент списка
			if (pRoot != nullptr) { pRoot->pPast = pLeft;}
			if (size == 0) { pRoot = pTail = pLeft;}
			else { pRoot = pLeft; }
			size++;
		}

	if (a == 2) // Добавление элемента справа
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
