﻿/*Создать двусвязный список, содержащий целые числа. Удалить лишние элементы так,
чтобы каждый элемент был не больше среднего арифметического всех элементов, следующих за ним.
Например, для списка 5 2 9 1 3 7 1 2 9, результат должен быть 2 1 3 1 2 9.
*/
#include <iostream>

using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { //вставка элемента в конец списка
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list* h, list* t) { //печать элементов списка
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}

//функция, удаляющая элементы так, чтобы список удовлетворял условиям задачи
void delete_average(list*& head, list*& tail) {
	int average = 0, count = 0; //переменные для подсчета среднего арифметического
	list* p = tail;
	average += p->inf;
	count++;
	p = p->prev;
	while (p != nullptr) { //идет с конца до начала списка
		if (p == head) { //если элемент является головой
			if (p->inf > average / count) {
				head = head->next;
				head->prev = nullptr;
				break;
			}
		}
		else { //если элемент находится в середине
			if (p->inf > average / count) {
				p->next->prev = p->prev;
				p->prev->next = p->next;
			}
			average += p->inf;
			count++;
			p = p->prev;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int x, n;
	list* head = NULL;
	list* tail = NULL;
	cout << "Введите количество элементов списка: ";
	cin >> n;
	cout << "Заполните список: \n";

	for (int i = 0; i < n; i++) { //заполнение списка
		cin >> x;
		push(head, tail, x);
	}

	delete_average(head, tail);
	print(head, tail);
}