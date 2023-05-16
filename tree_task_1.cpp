// Дано дерево. Удалить четные элементы
#include <iostream>

using namespace std;

struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree* node(int x) { //создание узла
	tree* n = new tree;
	n->inf = x;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inorder(tree* tr) { //симметричный обход дерева
	if (tr) {
		inorder(tr->left);
		cout << tr->inf;
		inorder(tr->right);
	}


void create(tree*& tr, int n) { //создание дерева
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
	create(tr, n);
}