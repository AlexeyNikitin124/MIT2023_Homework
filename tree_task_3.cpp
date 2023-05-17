// Дано идеально сбалансированное дерево. Определить количество листьев
#include <iostream>
#include <queue>

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

int leaf_count = 0;

void result(tree* tr) { //подсчет количество листьев у дерева
	if (tr) {
		result(tr->right);
		result(tr->left);
		if (!tr->left && !tr->right) {
			leaf_count++;
		}
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
	result(tr);
	cout << leaf_count;
}