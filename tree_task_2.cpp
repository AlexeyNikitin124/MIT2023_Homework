// Дано дерево. Определить степень узла Х.
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


void insert(tree*& tr, int x) { //вставка элемента в дерево
	tree* n = node(x);
	if (!tr) tr = n;
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf) {
				if (y->right)
					y = y->right;
				else {
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf) {
				if (y->left)
					y = y->left;
				else {
					n->parent = y;
					y->left = n;
					break;
				}
			}
		}
	}
}

tree* find(tree* tr, int x) { //поиск элемента
	if (!tr || x == tr->inf)
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);
	else
		return find(tr->right, x);
}

tree* Max(tree* tr) { //поиск максимального элемента 
	if (!tr->right) return tr;
	else return Max(tr->right);
}

tree* Prev(tree* tr, int x) { //поиск предыдущего элемента
	tree* n = find(tr, x);
	if (n->left)
		return Max(n->left);
	tree* y = n->parent;
	while (y && n == y->left) {
		n = y;
		y = y->parent;
	}
	return y;
}

void inorder(tree* tr) { //симметричный обход дерева
	if (tr) {
		inorder(tr->left);
		cout << tr->inf;
		inorder(tr->right);
	}
}

void result(tree* tr) { //определение глубины узла
	tree* p = tr;
	int count = 0;
	while (p) {
		if (p->parent == nullptr) {
			cout << count;
			break;
		}
		count++;
		p = Prev(p, p->inf);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, x;
	tree* tr = NULL;
	cout << "Введите количество элементов дерева: ";
	cin >> n;

	cout << "Заполните бинарное дерево: \n";
	for (int i = 0; i < n; ++i) {
		cin >> x;
		insert(tr, x);
	}

	cout << "Введите узел X: ";
	cin >> x;

	tree* p = find(tr, x);
	result(p);
}