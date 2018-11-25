#include "Header.h" //Структура Slist,eё функции и конструктор\деструктор, класс переменной ListNode

//Версия программы 1.3

int main() {
	SList theList;
	int i,ii,z = 0, j,a;
	char s;

	while (z < 1) { //Первый блок ввода данных, выбор размера списка
		system("cls");
		std::cout << "Welcome to my first program v1.4! Please enter number of strings: ";
		std::cin >> ii;
		if (ii > 0) { z = 1; }
		else { std::cout << "Inputting number must be positive! Please input positive number!\n"; system("pause"); }
	}

	for (j = 0; j < ii; j++) { //Заполнение листа
		theList.pushFront(j,1);
	}

	z = 0; 	a = ii; //зануляем z для следующего цикла, запоминаем введеное i

	while (z < 1) { //Второй блок ввода данных, выбор отображения списка
		std::cout << "Please, select display order:\n\n1.From left to right\n2.From right to left\n\n";
		std::cin >> i;
		if (i == 1) { z = 1; }
		else if (i==2){ z = 1; }
		else { std::cout << "Incorrect input number. Please, input 1 or 2\n"; system("pause"); system("cls"); }
	}
	z = 0;
	int zz = 0;
	char ss;
	while (1) { //Третий блок ввода данных, выбор действий над списком
		system("cls");
		std::cout << "List status:\nSize of list: " << theList.size << std::endl << "Your list: ";
		theList.printList(i);
		std::cout <<	"\nChoose next operation:\n" 
						"1. Add or delete string\n"
						"2. Edit string\n"
						"3. Exit program\n\n";
		std::cin >> s;

		switch (s) {

			case '1':
				while (zz < 0) {
					system("cls");
					std::cout << "List status:\nSize of list: " << theList.size << std::endl << "Your list: ";
					theList.printList(i);
					std::cout << "\nChoose next operation:\n"
						"a. Add string to the right\n"
						"b. Add string to the left\n"
						"c. Delete string from left\n"
						"d. Delete string from right\n"
						"e. Return to previous menu\n";
					std::cin >> ss;
					switch (ss) {
					case 'a':
						theList.pushFront(ii, 1);
						ii++;
						//break;

					case 'b':
						theList.pushFront(ii, 2);
						ii++;
						break;


					case 'c':
						if (theList.size == 0)
						{
							std::cout << "\nWarning! Empty list, please add some strings!\n\n";
							system("pause");
							break;
						}
						else
						{
							theList.popFront(1);
							ii--;
							break;
						}
					case 'd':
						if (theList.size == 0)
						{
							std::cout << "Warning! Empty list, please add some strings!\n";
							system("pause");
							break;
						}

						else
						{
							theList.popFront(2);
							ii--;
							break;
						}
					case 'e':
						zz = 1;
						break;

						} //end of second switch
					} //end of while zzz
						
			case '2':	exit(0);
						break;

			case '3':	exit(0);
						break;

			default:	std::cout << "\nIncorrect input number\n\n"; 
						system("pause");

		} //end of switch
	} //end of third while(1)
} // end of main()
