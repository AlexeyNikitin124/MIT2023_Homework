/*Создать двусвязный список, содержащий целые числа.
После всех чисел, равных минимальному числу, вставить последний четный элемент.
Например, было 2 8 2 1 6 8 8 1 2 2 8 2 1. Стало 2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2
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

//вставка в список послне некоторого элемента списка
void insert_after(list_str*& h, list_str*& t, list_str* r, int y) {
	list_str* p = new list_str;
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

int main() {
	setlocale(LC_ALL, "RUS");
	list_str* head = NULL;
	list_str* tail = NULL;
	int n, x;
	cout << "Введите количество элементов списка: ";
	cin >> n;
	cout << "Заполните список: \n";

	int chet;
	for (int i = 0; i < n; i++) { //заполнение списка
		cin >> x;
		if (x % 2 == 0) {
			chet = x;
		}
		push(head, tail, x);
	}
}