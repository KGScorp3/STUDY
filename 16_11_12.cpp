#include <iostream>

struct ListNode //Тип переменных в списке
{
public:
	int nData;
//private:
	ListNode* pNext; //Указатель на другую такую же структуру
	ListNode() {};
//public:
	//friend class Slist;
};

struct SList //Структура списка
{
	ListNode *pRoot; //Указатель на первый элемент списка
public:

	SList();
	void pushFront(const int _nData); //функция добавления элемента в список
	int popFront(); //функция удаления элемента списка
	void printList(); //вывод элемента списка
	//~Slist();
};

/*Slist()::Slist(){
void pushFront(const int _nData);
int popFront();
void printList();
}*/

/*Slist::~Slist() {
	ListNode *pTemp;
	while (pRoot != nullptr) {
		pTemp = pRoot;
		pRoot = pRoot->pNext;
		delete pTemp;
	}
*/



SList::SList() : pRoot(nullptr) //Первоначальное значение элемента списка
{
}

void SList::printList() //Фукнция вывода
{
	if (pRoot == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return; //Пишем ретурн чтобы остановить функцию на этом моменте
	}

	ListNode *pIt = pRoot;

	while (pIt != nullptr)
	{
		std::cout << " " << pIt->nData;
		pIt = pIt->pNext;
	}
	std::cout << std::endl;
}

void SList::pushFront(const int _nData) //Функция добавления элементов
{
	ListNode *pNewNode = new ListNode;
	pNewNode->nData = _nData;
	pNewNode->pNext = pRoot;
	pRoot = pNewNode;

}

int SList::popFront()
{
	ListNode *pTemp = pRoot;
	pRoot = pRoot -> pNext;
	delete pTemp;

	return 0;
}


int main() {
	SList theList;

	/*if (theList.pRoot == nullptr)
	{
		std::cout << "Null!" << std::endl;
	}
	else
	{
		std::cout << "Not null!" << std::endl;
	}*/

	int i,s,j=1;

	std::cout << "Welcome to my first program v1.1! Please enter number of strings: ";
	std::cin >> i;
	for (s = 0; s < i; s++) {
		theList.pushFront(s);
	}

	while (1) {
		system("cls");
		std::cout << "Your list: ";
		theList.printList();
		std::cout << "\n";
		std::cout << "Choose next operation:\n1. Add string\n2. Delete string\n3. Exit program\n\n";
		std::cin >> s;
		switch (s) {
		case 1: theList.pushFront(i); i++; break;
		case 2: if (theList.pRoot == nullptr) { std::cout << "\nWarning! Empty List, please add some numbers!\n\n"; system("pause"); break; }
				else { theList.popFront(); i--; break; };
		case 3: exit(0); break;
		default: std::cout << "\nIncorrect input number\n\n"; system("pause");

		}

		
		
	}
}