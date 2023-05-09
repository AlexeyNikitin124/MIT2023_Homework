/*Создать двусвязный список, содержащий целые числа. Удалить лишние элементы так,
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


void del_node(list*& h, list*& t, list* r) { //удаление элемента списка
	if (r == h && r == t) { //удаление единственного элемента списка
		h = t = NULL;
	}
	else if (r == h) { //удаление первого элемента списка
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) { //удаление концевого элемента списка
		t = t->prev;
		t->next = NULL;
	}
	else { //удаление элемента из середины списка
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
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
}