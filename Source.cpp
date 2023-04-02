#include "BT.h"
#include "stdio.h"
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
using namespace std;

/*
В данной работе необходимо улучшить свой класс из предыдущей лабораторной работы, полностью делегировав управление памятью стандартному контейнеру.
1. Конструктор копирования, оператор присваивания и деструктор в классе должны неявно генерироваться компилятором (см. ключевое слово default); при этом операции копирования должны выполнять глубокое клонирование объекта (т. е. внешнее поведение класса должно остаться таким же, каким и было).
2. Внутри класса не должно остаться ни указателей, ни ручного управления памятью.
3. В качестве поля класса должен появиться стандартный контейнер std::vector или std::list/std::forward_list (в зависимости от того, использовали вы массив или связный список в предыдущей лабораторной работе).
4. Элементы, хранящиеся в классе, должны быть константно итерируемыми с помощью range-based for loop (for(auto i: v) {}).В частности, это означает, что вы должны определить методы begin() и end() для вашего класса и возвращать соответствующий итератор.
5. Распечатку элементов проводить с помощью range - based for loop(for (auto i : v) { }).

*/

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
};

int menu_1()
{
	std::cout << "Выберите, как вы хотите продолжить работу:\n";
	std::cout << "Инвертировать изображение: Enter\nСложить с другим изображением: 1\nУмножить на другое изображение: 2\nСложить с булевским значением: 3\nУмножить на булевское значение: 4\nВычислить коэффициент заполнения изображения: 5\nВыход из прог-мы: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 27)) return key;
	}
}

int menu_2()
{
	std::cout << "Вернуться: Enter\nВыход из прог-мы: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 27)) return key;
	}
}

void print_tree(BT* tree) {
	tree->print();
}


int main() {
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "RUS");
		while (true) {
			system("cls");
			std::cout << "Меню 1:\n";
			std::cout << "[1] - Создать дерево(до 2х деревьев может существовать одновременно)\n";
			std::cout << "[2] - Удалить текущее дерево\n";
			std::cout << "[3] - Удалить элемент в дереве\n";
			std::cout << "[4] - Выполнить задание\n";
			std::cout << "[5] - Результаты тестов\n";
			std::cout << "[->] - Следующее дерево\n";//77
			std::cout << "[<-] - Предыдущее дерево\n";//75
			std::cout << "[ESC] - Выход\n";

			BT* array[2];
			int size = 0;
			int cur = -1;

			if (cur < 0) {
				std::cout << "Нет деревьев\n";
			}
			else {
				if (cur >= size) {
					std::cout << "Добавлено максимальное количество деревьев\n";
				}
				else print_tree(array[cur]);
			}

			int m = get_key();
			
			switch (m)
			{
			case 49:
				
				break;
			case 50:
				
				break;
			case 51:
				
				break;
			case 52:
				
				break;
			case 53:
				
				break;
			case 77:

				break;
			case 75:

				break;
			case 27:
				return 0;
				break;
			}
		}
	}
}