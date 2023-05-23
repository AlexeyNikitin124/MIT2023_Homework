// Дано дерево. Определить глубину узла X.

#include <iostream>

using namespace std;

struct tree {
	int inf;
	tree* right;
	tree* left;
};

tree* node(int x) { //создание узла
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	return n;
}

void create(tree*& tr, int n) { //создание идеально сбалансированного дерева
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, x;
	tree* tr = NULL;
	cout << "Введите количество элементов дерева: ";
	cin >> n;

	cout << "Заполните бинарное дерево: \n";
	create(tr, n);
}