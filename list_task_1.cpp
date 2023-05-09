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

void delete_duplicate_elements(list*& head, list*& tail) { //функция, удаляющая повторяющиеся элементы
	while (p != nullptr) {
		if (m[p->inf] == false) { // элемент еще не встречался
			m[p->inf] = true;
			p = p->prev;
		}
		else if (p->prev == nullptr){ // p->prev равен nullptr, т.е. это последний узел в списке
			list_str* temp = p;
			p = nullptr;
			del_node(head, tail, temp);
			break;
		}
		else  (p->prev != nullptr) { // элемент уже встречался, удаляем данный узел, если p->prev не равен nullptr
			list_str* temp = p;
			p = p->prev;
			del_node(head, tail, temp);
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	list* head = NULL;
	list* tail = NULL;
	int n, x;
	cout << "Введите количество элементов списка: ";
	cin >> n;
	cout << "Заполните список: \n";

	map<int, bool> m; //хранит информацию для каждого элемента, встречался ли ранее
	for (int i = 0; i < n; i++) { //заполнение списка
		cin >> x;
		push(head, tail, x);
		m[x] = false;
	}

	delete_duplicate_elements(head, tail);
	print(head, tail);
}