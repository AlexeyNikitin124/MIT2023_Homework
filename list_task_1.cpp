/*Создать двусвязный список из целых чисел. Удалить все повторяющиеся элементы,
 оставив только их последние вхождения. Например, было 1 2 2 1 3 4 5 1 2 5 4 3 5. Стало 1 2 4 3 5.
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

list* find(list* h, list* t, int x) { //поиск элемента в списке
	list* p = h;
	while (p) {
		if (p->inf == x) break;
		p = p->next;
	}
	return p;
}

void print(list* h, list* t) { //печать элементов списка
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}

//функция вставки элемента после некоторого элемента списка
void insert_after(list*& h, list*& t, list* r, int y) {
	list* p = new list;
	p->inf = y;
	if (r == t) {
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}
	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}

}

//удаление элемента после некоторого элемента списка
void del_node(list*& h, list*& t, list* r) {
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
	list* head = NULL;
	list* tail = NULL;
	int n, x;
	cout << "Введите количество элементов списка: ";
	cin >> n;
	cout << "Заполните список: \n";

	for (int i = 0; i < n; i++) { //заполнение списка
		cin >> x;
		push(head, tail, x);
	}
}