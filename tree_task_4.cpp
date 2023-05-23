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

int Depth(tree* tr, int x, int depth) { //определение глубины узла
	if (tr == NULL) {
		return -1; // узел не найден
	}
	if (tr->inf == x) {
		return depth; // найден искомый узел
	}
	int leftDepth = Depth(tr->left, x, depth + 1); // ищем в левом поддереве
	if (leftDepth != -1) {
		return leftDepth; // узел найден в левом поддереве
	}
	int rightDepth = Depth(tr->right, x, depth + 1); // ищем в правом поддереве
	return rightDepth; // возвращаем глубину из правого поддерева
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, x;
	tree* tr = NULL;
	cout << "Введите количество элементов дерева: ";
	cin >> n;

	cout << "Заполните бинарное дерево: \n";
	create(tr, n);

	cout << "Введите значение узла X: ";
	cin >> x;
	int depth = Depth(tr, x, 0);
	if (depth == -1) {
		cout << "Узел не найден в дереве";
	}
	else {
		cout << "Глубина узла равна: "<< depth;
	}
}