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

tree* find(tree* tr, int x) {

}
tree* Min(tree* tr) { //поиск минимального элемента 
	if (!tr->left) return tr;
	else return Min(tr->left);
}

tree* Max(tree* tr) { //поиск максимального элемента 
	if (!tr->right) return tr;
	else return Max(tr->right);
}

tree *Next(tree *tr, int x) { //поиск следущего элемента дерева
	tree* n = find(tr, x);
	if (n->right)
		return Min(n->right);
	tree* y = n->parent;
	while (y && n == y->right) {
		n = y;
		y = y->parent;
	}
	return y;
}

void Delete(tree*& tr, tree* v) { //удаление узла
	tree* p = v->parent;
	if (!p) { tr = NULL; } // дерево содержит один узел
	else if (!v->left && !v->right) { //если нет детей
		if (p->left == v) p->left = NULL;
		if (p->right == v) p->right = NULL;
		delete v;
	}
	else if (!v->left || !v->right) { //если только один ребенок
		if (!p) { //если у корня только 1 ребенок
			if (!v->left) { //если этот ребенок правый
				tr = v->right;
				v->parent = NULL;
			}
			else { //если этот ребенок левый
				tr = v->left;
				v->parent = NULL;
			}
		}
		else {
			if (!v->left) { //если есть правый ребенок
				if (p->left == v)  //если удаляемый узел является левым ребенком
					p->left = v->right;
				else  //если удаляемый узел является паравым ребенком
					p->right = v->right;
				v->right->parent = p;
			}
			else { //аналогично для левого ребенка
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
				v->left->parent = p;
			}
			delete v;
		}
	}
	else { //есть оба ребенка

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