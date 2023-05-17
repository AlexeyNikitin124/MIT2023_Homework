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

void insert(tree*& tr, int x) { //вставка элемента в дерево
	tree* n = node(x);
	if (!tr) tr = n; //если дерево пустое
	else {
		tree* y = tr;
		while (y) { //ищем куда вставить
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

tree* Min(tree* tr) { //поиск минимального элемента 
	if (!tr->left) return tr;
	else return Min(tr->left);
}

tree* Max(tree* tr) { //поиск максимального элемента 
	if (!tr->right) return tr;
	else return Max(tr->right);
}

tree* Next(tree* tr, int x) { //поиск следущего элемента дерева
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
				else  //если удаляемый узел является правым ребенком
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
		tree* succ = Next(tr, v->inf); //следующий за удаляемым узлом
		v->inf = succ->inf;
		if (succ->parent->left == succ) { //если succ левый ребенок
			succ->parent->left == succ->right;
			if (succ->right) //если этот ребенок существует
				succ->right->parent = succ->parent; //его родителем становится "дед"
		}
		else { //аналогично если succ - правый ребенок
			succ->parent->right == succ->right;
			if (succ->right) //если этот ребенок существует
				succ->right->parent = succ->parent; //его родителем становится "дед"
		}
		delete succ;
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
}